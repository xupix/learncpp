#include <iostream>

int sumTo(int num)
{
  int total{ 0 };
  for(int count{ 1 }; count <= num; ++count)
  {
    total += count;
  }

  return total;
}

int main()
{
  std::cout << "Enter a positive number: ";
  int num{};
  std::cin >> num;

  std::cout << "The sum from 0 to " << num << " is: " << sumTo(num) << '\n';

  return 0;
}
