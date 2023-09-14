#include <iostream>

enum AnimalType
{
  cat,
  dog,
  chicken,
  snake,
};

std::string_view animalName(AnimalType type)
{
  switch (type)
  {
  case cat:
    return "cat";
  case dog:
    return "dog";
  case chicken:
    return "chicken";
  case snake:
    return "snake";
  default:
    return "";
  }
}

int numLegs(AnimalType type)
{
  switch (type)
  {
  case cat:
    return 4;
  case dog:
    return 4;
  case chicken:
    return 2;
  case snake:
    return 0;
  default:
    return 0;
  }
}

int main()
{
  AnimalType animal{snake};
  std::cout << "A " << animalName(animal) << " has " << numLegs(animal) << " legs\n";

  return 0;
}
