#include <iostream>

void clearCinBuffer();
void handleCinBuffer();
int getNumber(int minNumber, int maxNumber);

int main()
{
  constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
  constexpr int numElementsInArray{ static_cast<int>(std::size(array)) };
  constexpr int minNumber{ 1 };
  constexpr int maxNumber{ 9 };

  int choice { getNumber(minNumber, maxNumber) };
  int choiceIndex {};

  for (int index{ 0 }; index < numElementsInArray; ++index)
  {
    std::cout << array[index] << ' ';
    if (array[index] == choice)
    {
      choiceIndex = index;
    }
  }
  std::cout << '\n';

  std::cout << "The number " << choice << " has index " << choiceIndex << '\n';
  

  return 0;
}

void clearCinBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void handleCinBuffer()
{
  if(!std::cin)
  {
    if(std::cin.eof())
    {
      exit(0);
    }

    std::cin.clear();
    clearCinBuffer();
  }
  else
  {
    clearCinBuffer();
  }
}

int getNumber(int minNumber, int maxNumber)
{
  while(true)
  {
    std::cout << "Enter a number between 1 and 9: ";
    int userChoice{};
    std::cin >> userChoice;

    handleCinBuffer();

    if(userChoice >= minNumber && userChoice <= maxNumber)
    {
      return userChoice;
    }
  }
}
