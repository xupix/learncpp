#include <string_view>
#include <string>
#include <array>
#include <iostream>

namespace Animal
{
  enum Type
  {
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,
    max_types,
  };

  struct Data
  {
    std::string_view name{};
    int numLegs{};
    std::string_view sound{};
  };

  using namespace std::string_view_literals;
  std::array<Data, 6> animalsData{
      {
          {"chicken"sv, 2, "cluck"sv},
          {"dog"sv, 4, "woof"sv},
          {"cat"sv, 4, "meow"sv},
          {"elephant"sv, 4, "pawoo"sv},
          {"duck"sv, 2, "quack"sv},
          {"snek"sv, 0, "hissss"sv},
      }};

  static_assert(std::ssize(animalsData) == Animal::max_types && "Array size not a match");
}

std::istream &operator>>(std::istream &in, Animal::Type &animal)
{
  std::string input{};
  std::getline(in >> std::ws, input);

  for (int i{0}; i < Animal::max_types; ++i)
  {
    if (input == Animal::animalsData[i].name)
    {
      animal = static_cast<Animal::Type>(i);
      return in;
    }
  }

  in.setstate(std::ios_base::failbit);
  return in;
}

void printAnimal(const Animal::Data &animal)
{
  // i'm handling elephant specifically. if more animals are added starting
  // with a vowel it's an easy update to do to the code.
  std::cout << ((animal.name == "elephant") ? "An " : "A ") << animal.name << " has " << animal.numLegs << " legs and says " << animal.sound << ".\n";
}

int main()
{
  std::cout << "Enter an animal: ";
  Animal::Type userAnimal{};
  std::cin >> userAnimal;

  if (!std::cin)
  {
    std::cin.clear();
    std::cout << "That animal couldn't be found.\n";
    userAnimal = Animal::max_types;
  }
  else
    printAnimal(Animal::animalsData[userAnimal]);

  std::cout << "\nHere is the data for the rest of the animals:\n";
  for (const auto animal : Animal::animalsData)
  {
    if (animal.name != Animal::animalsData[userAnimal].name)
      printAnimal(animal);
  }

  return 0;
}
