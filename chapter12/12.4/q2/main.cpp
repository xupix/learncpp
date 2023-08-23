#include <iostream>

int addDigits(int x)
{
  if (x % 10 == x) return x;
  return (x % 10) + addDigits(x / 10);
}

int main()
{
  std::cout << addDigits(93427) << '\n';
  std::cout << addDigits(987654321) << '\n';

  return 0;
}
