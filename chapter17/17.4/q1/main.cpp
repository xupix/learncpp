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
  constexpr std::array items{
      Item{"sword", 5},
      Item{"dagger", 3},
      Item{"club", 2},
      Item{"spear", 7}};

  for (const auto &element : items)
  {
    std::cout << "A " << element.name << " costs " << element.gold << " gold.\n";
  }

  return 0;
}
