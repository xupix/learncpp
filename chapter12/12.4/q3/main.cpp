// the solution version is cleaner but this one works just the same.

#include <iostream>

void printBinary(unsigned int x)
{
  if (x == 1) 
  {
    std::cout <<  1;
    return;
  }
  if (x != 0) printBinary(x / 2);
  std::cout << (x % 2);
}

int main()
{
  std::cout << "Please enter a number: ";
  int x{};
  std::cin >> x;

  // not static casting since the user shouldn't care the function uses an
  // unsigned int. it's better to implicitly cast in my opion.
  printBinary(x);
  std::cout << '\n';

  return 0;
}
