#include <iostream>
#include <string>
#include <algorithm>

int main()
{
  std::cout << "How many names would you like to enter? ";
  std::size_t length{};
  std::cin >> length;

  auto* names{ new std::string[length]{} };
  for (int i { 0 }; i < length ; ++i)
  {
    std::cout << "Enter name #" << (i + 1) << ": ";
    std::getline(std::cin >> std::ws, names[i]);
  }

  std::sort(names, names + length);

  std::cout << "\nHere is your sorted list:\n";
  for(int i{ 0 }; i < length; i++)
  {
    std::cout << "Name #" << (i + 1) << ": " << names[i] << '\n';
  }

  return 0;
}
