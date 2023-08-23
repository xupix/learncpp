#include <iostream>
#include <string_view>

enum class Animal
{
  pig, 
  chicken, 
  goat, 
  cat, 
  dog, 
  duck,
};

constexpr std::string_view getAnimalName(Animal animal)
{
  using enum Animal;
  switch(animal)
  {
    case pig: return "pig";
    case chicken: return "chicken";
    case goat: return "goat";
    case cat: return "cat";
    case dog: return "dog";
    case duck: return "duck";
    default: return "no such animal";
  }
}

void printNumberOfLegs(Animal animal)
{
  std::cout << "A " << getAnimalName(animal);
  using enum Animal;
  switch(animal)
  {
    case chicken: 
    case duck: 
    {
      std::cout << " has 2 legs\n";
      return;
    }
    case pig:
    case goat:
    case cat:
    case dog: 
    {
      std::cout << " has 4 legs\n";
      return;
    }
    default: 
    {
      std::cout << "no such animal\n";
      return;
    }
  }
}

int main()
{
  Animal cat{ Animal::cat };
  Animal chicken{ Animal::chicken };
  Animal duck{ Animal::duck };
  Animal goat{ Animal::goat };

  printNumberOfLegs(cat);
  printNumberOfLegs(chicken);
  printNumberOfLegs(duck);
  printNumberOfLegs(goat);

  return 0;
}
