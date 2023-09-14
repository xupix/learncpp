#include <iostream>

struct Cat
{
  std::string_view name{"cat"};
  int numLegs{4};
};

struct Dog
{
  std::string_view name{"dog"};
  int numLegs{4};
};

struct Chicken
{
  std::string_view name{"chicken"};
  int numLegs{2};
};

struct Snake
{
  std::string_view name{"snake"};
  int numLegs{0};
};

int main()
{
  Snake animal;
  std::cout << "a " << animal.name << " has " << animal.numLegs << " legs";

  return 0;
}
