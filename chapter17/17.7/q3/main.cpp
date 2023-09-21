#include <iostream>

int main()
{
  const int array[]{0, 1, 4, 9};

  while (true)
  {
    std::cout << "Enter a single digit integer, or -1 to quit: ";
    int choice{};
    std::cin >> choice;

    if (choice == -1)
      break;

    bool found{false};
    for (const auto element : array)
      if (element == choice)
        found = true;

    std::cout << choice << " is " << ((found) ? "" : "not ") << "a perfect square\n";
  }

  std::cout << "Bye\n";
  return 0;
}
