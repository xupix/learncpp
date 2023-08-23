#include <iostream>

void fizzbuzzpop(int num)
{
  for(int count{ 1 }; count <= num; ++count)
  {
    if(count % 3 == 0)
    {
      std::cout << "fizz";
    }
    if(count % 5 == 0)
    {
      std::cout << "buzz";
    }
    if(count % 7 == 0)
    {
      std::cout << "pop";
    }
    if(count % 3 != 0 && count % 5 != 0 && count % 7 != 0)
    {
      std::cout << count;
    }
    std::cout << '\n';
  }
}

int main()
{
  fizzbuzzpop(150);

  return 0;
}
