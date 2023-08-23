#include <iostream>

int main()
{
  int outer{ 1 };

  while(outer <= 5)
  {
    int innerA{ 5 };
    while (outer <= innerA)
    {
      std::cout << ' ' << ' ';
      --innerA;
    }

    int innerB{ 1 };
    while (innerB <= outer)
    {
      std::cout << innerB << ' ';
      ++innerB;
    }

    std::cout << '\n';
    ++outer;
  }

  return 0;
}
