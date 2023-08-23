#include <iostream>

void swap(int& a, int& b)
{
  int temp{ a };
  a = b;
  b = temp;
}

int main()
{
  int a = 99;
  int b = 15;
  std::cout << a << ' ' << b << '\n';
  swap(a, b);
  std::cout << a << ' ' << b << '\n';

  return 0;
}
