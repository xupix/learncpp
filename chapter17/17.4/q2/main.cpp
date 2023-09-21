#include <string_view>
#include <array>
#include <iostream>

struct Item
{
  std::string_view name{};
  int gold{};
};

int main()
{
  constexpr std::array<Item, 4> items{{{"sword", 5},
                                       {"dagger", 3},
                                       {"club", 2},
                                       {"spear", 7}}};

  for (const auto &element : items)
  {
    std::cout << "A " << element.name << " costs " << element.gold << " gold.\n";
  }

  return 0;
}
