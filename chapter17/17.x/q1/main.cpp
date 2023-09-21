#include <iostream>
#include <numeric>
#include <array>

namespace Items
{
  enum Types
  {
    healthPotions,
    torches,
    arrows,
    max_types,
  };
}

int countTotalItems(const std::array<int, Items::max_types> &itemList)
{
  return std::reduce(itemList.begin(), itemList.end());
}

int main()
{
  std::array itemList{2, 5, 10};

  std::cout << "Total items: " << countTotalItems(itemList) << '\n';
  std::cout << "Torches: " << itemList[Items::torches] << '\n';
}
