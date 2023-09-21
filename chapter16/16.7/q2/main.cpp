#include <string_view>
#include <iostream>
#include <vector>

template <typename T>
bool isValueInArray(const auto &arr, const T &value)
{
  for (const auto element : arr)
    if (element == value)
      return true;

  return false;
}

int main()
{
  std::vector<std::string_view> arr{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

  std::cout << "Enter a name: ";
  std::string search{};
  std::cin >> search;

  bool found{isValueInArray(arr, search)};

  (found) ? std::cout << search << " was found.\n" : std::cout << search << " was not found.\n";

  return 0;
}
