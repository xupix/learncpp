#include <string_view>
#include <iostream>
#include <vector>

int main()
{
  std::vector<std::string_view> arr{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

  std::cout << "Enter a name: ";
  std::string search{};
  std::cin >> search;

  bool found{false};
  for (auto name : arr)
  {
    if (name == search)
    {
      found = true;
      break;
    }
  }

  (found) ? std::cout << search << " was found.\n" : std::cout << search << " was not found.\n";

  return 0;
}
