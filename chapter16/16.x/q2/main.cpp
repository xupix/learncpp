#include <vector>
#include <iostream>

using namespace std::literals::string_view_literals; // for sv suffix

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

std::string_view itemToString(Items::Types item)
{
  switch (item)
  {
  case Items::healthPotions:
    return "health potion"sv;
  case Items::torches:
    return "torch"sv;
  case Items::arrows:
    return "arrow"sv;

  default:
    return "No such item"sv;
  }
}

int getTotalItems(const auto &player)
{
  int totalItems{0};
  for (auto &item : player)
    totalItems += item;

  return totalItems;
}

void printTotalItems(int itemCount)
{
  std::cout << "You have " << itemCount << " total items\n";
}

void printInventory(const auto &player)
{
  for (int i{0}; i < Items::max_types; ++i)
  {
    std::cout << "You have " << player[static_cast<Items::Types>(i)] << ' ' << itemToString(static_cast<Items::Types>(i));
    (player[static_cast<Items::Types>(i)] > 1) ? std::cout << "s\n" : std::cout << '\n';
  }
}

void printPlayerInfo(const auto &player)
{
  printInventory(player);

  printTotalItems(getTotalItems(player));
}

int main()
{
  std::vector player{1, 5, 10};

  assert(std::ssize(player) == Items::max_types && "Array size incorrect");

  printPlayerInfo(player);

  return 0;
}
