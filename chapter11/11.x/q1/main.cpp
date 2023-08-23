#include <array>
#include <iostream>
#include <numeric>

namespace Player
{
  enum Player
  {
    healthPotions,
    torches,
    arrows,
    numObjects,
  };
};

int countTotalItems(const std::array<int, Player::numObjects>& items)
{
  return std::reduce(items.begin(), items.end());
}

int main()
{
  std::array playerItems { 2, 5, 10 };

  // print total number of items
  std::cout << countTotalItems(playerItems) << '\n';
  // print number of torches
  std::cout << playerItems[Player::torches] << '\n';

  return 0;
}
