#include <iostream>

void fizzbuzz(int num)
{
  for(int count{ 1 }; count <= num; ++count)
  {
    if(count % 3 == 0 && count % 5 == 0)
    {
      std::cout << "fizzbuzz\n";
    }
    else if(count % 3 == 0)
    {
      std::cout << "fizz\n";
    }
    else if(count % 5 == 0)
    {
      std::cout << "buzz\n";
    }
    else
    {
      std::cout << count << '\n';
    }
  }
}

int main()
{
  std::cout << "Choose a number to fizzbuzz to: ";
  int value{};
  std::cin >> value;

  fizzbuzz(value);

  return 0;
}
