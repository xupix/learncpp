#include <iostream>

int factorial(int x)
{
  if (x == 1) return x;
  return x * factorial(x - 1);
}

int main()
{
  std::cout << factorial(2) << '\n';
  std::cout << factorial(3) << '\n';
  std::cout << factorial(4) << '\n';
  std::cout << factorial(5) << '\n';
  std::cout << factorial(6) << '\n';
  std::cout << factorial(7) << '\n';

  return 0;
}
