#include <iostream>
#include <string>

int main()
{
  std::string_view names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

  std::cout << "Enter a name: ";
  std::string searchName{};
  std::cin >> searchName;

  for(auto name : names)
  {
    if (name == searchName)
    {
      std::cout << searchName << " was found.\n";
      // preferred returning early instead of using a flag for found name but
      // that is just as valid.
      return 0;
    }
  }
  std::cout << searchName << " was not found.\n";

  return 0;
}
