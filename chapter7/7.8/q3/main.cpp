#include <iostream>

int main()
{
  int outer{ 5 };
  while (outer >= 1)
  {
    int inner{ 0 };
    while (outer > inner)
    {
      std::cout << outer - inner << ' ';
      ++inner;
    }

    std::cout << '\n';
    --outer;
  }

  return 0;
}
