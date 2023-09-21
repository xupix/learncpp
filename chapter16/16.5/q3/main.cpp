#include "ClearInput.h"

#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T> &v)
{
  for (int i{0}; i < static_cast<int>(v.size()); ++i)
  {
    std::cout << v[static_cast<std::size_t>(i)] << ' ';
  }
  std::cout << '\n';
}

int main()
{
  std::vector arr{4, 6, 7, 3, 8, 2, 1, 9};
  // std::cout << "Enter a number between 1 and 9: ";

  int num{};
  while (num < 1 || num > 9)
  {
    std::cout << "Enter a number between 1 and 9: ";
    std::cin >> num;
    ClearInput::handleCinBuffer();
  }

  printArray(arr);

  bool found{false};
  for (int i{0}; i < std::ssize(arr); ++i)
  {
    if (arr[static_cast<std::size_t>(i)] == num)
    {
      std::cout << "The number " << num << " has index " << i << '\n';
      found = true;
      break;
    }
  }
  if (!found)
    std::cout << "The number " << num << " could was not found\n";

  return 0;
}
