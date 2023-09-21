#include <vector>
#include <iostream>

namespace Animals
{
  enum Types
  {
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,
    max_types,
  };
};

int main()
{
  std::vector animalLegs{2, 4, 4, 4, 2, 0};

  assert(std::ssize(animalLegs) == Animals::max_types && "Array size is wrong");

  std::cout << "An elephant has " << animalLegs[static_cast<std::size_t>(Animals::elephant)] << " legs.\n";
  std::cout << "A snake has " << animalLegs[static_cast<std::size_t>(Animals::snake)] << " legs.\n";

  return 0;
}
