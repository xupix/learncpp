// q6
#include <iostream>

int askUserForNumber()
{
  std::cout << "Give a number between  0 and 255: ";
  int number{};
  std::cin >> number;

  return number;
}

int main()
{
  int number{ askUserForNumber() };
  [[maybe_unused]] int one{};
  [[maybe_unused]] int two{};
  [[maybe_unused]] int four{};
  [[maybe_unused]] int eight{};
  [[maybe_unused]] int sixteen{};
  [[maybe_unused]] int thirtyTwo{};
  [[maybe_unused]] int sixtyFour{};
  [[maybe_unused]] int oneTwentyEight{};

  if (number >= 128)
  {
    oneTwentyEight = 1;
    number -= 128;
  }

  if (number >= 64)
  {
    sixtyFour = 1;
    number -= 64;
  }

  if (number >= 32)
  {
    thirtyTwo = 1;
    number -= 32;
  }

  if (number >= 16)
  {
    sixteen = 1;
    number -= 16;
  }

  if (number >= 8)
  {
    eight = 1;
    number -= 8;
  }

  if (number >= 4)
  {
    four = 1;
    number -= 4;
  }

  if (number >= 2)
  {
    two = 1;
    number -= 2;
  }

  if (number >= 1)
  {
    one = 1;
    number -= 1;
  }

  std::cout << "The number in 8-bit binary is: " << oneTwentyEight << sixtyFour << thirtyTwo << sixteen << ' ' << eight << four << two << one << '\n';

  return 0;
}
