#include <iostream>

void printArray(const char *str)
{
  while (*str != '\0')
    std::cout << *str++;
}

void printArrayReversed(const char *str)
{
  const char *ptr{str};

  while (*ptr != '\0')
    ++ptr;

  while (ptr != str)
    std::cout << *ptr--;
}

int main()
{
  printArray("Hello world!");

  std::cout << "\n\n";

  printArrayReversed("Hello world!");

  return 0;
}
