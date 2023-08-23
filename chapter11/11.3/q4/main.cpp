#include <iostream>
#include <string>

void fizzBuzzPlus(int maxNumber);

int main()
{
  fizzBuzzPlus(150);

  return 0;
}

void fizzBuzzPlus(int maxNumber)
{
  int divisors[]{ 3, 5, 7, 11, 13, 17, 19 };
  std::string_view divisorsWords[]{ "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };
  static_assert(std::size(divisors) == std::size(divisorsWords));
  // doing the casting here to avoid doing it every inner loop iteration and
  // to improve readability
  int divisorListSize{ static_cast<int>(std::size(divisors)) };

  for(int number{ 1 }; number < maxNumber; ++ number)
  {
    bool isPrinted { false };
    for(int divisorIndex{ 0 }; divisorIndex < divisorListSize; ++divisorIndex)
    {
      if(number % divisors[divisorIndex] == 0)
      {
        std::cout << divisorsWords[divisorIndex];
        isPrinted = true;
      }
    }
    if (!isPrinted)
    {
      std::cout << number;
    }
    std::cout << '\n';
  }
}
