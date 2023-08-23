#include <iostream>

int getInteger()
{
  std::cout << "Enter an integer: ";
  int integer {};
  std::cin >> integer;

  return integer;
}

bool isEven(int integer)
{
  return (integer % 2) == 0;
}

int main()
{
  int integer{ getInteger() };

  if (isEven(integer))
  {
    std::cout << integer << " is even.\n";
  } else
  {
    std::cout << integer << " is odd. \n";
  }

  return 0;
}
