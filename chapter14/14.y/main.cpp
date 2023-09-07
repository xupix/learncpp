#include "Board.h"
#include "ClearCin.h"
#include "Direction.h"

#include <cstdlib>
#include <iostream>

namespace UserInput
{
  bool isValidCommand(char ch)
  {
    return ch == 'w' ||
           ch == 'a' ||
           ch == 's' ||
           ch == 'd' ||
           ch == 'q';
  }

  char getUserInput()
  {
    char ch{};
    std::cin >> ch;
    handleCinBuffer();

    return ch;
  }

  char turn()
  {
    char ch{getUserInput()};
    while (!isValidCommand(ch))
    {
      ch = getUserInput();
    }

    return ch;
  }

  Direction getDirection(char ch)
  {
    switch (ch)
    {
    case 'w':
      return Direction(Direction::up);
    case 'a':
      return Direction(Direction::left);
    case 's':
      return Direction(Direction::down);
    case 'd':
      return Direction(Direction::right);
    }

    assert(0 && "Wrong direction in getDirection");
    return Direction{Direction::up};
  }
};

int main()
{
  Board board{};
  board.initialize();
  std::cout << board;

  std::cout << "\nEnter a command: ";

  while (true)
  {
    char ch{UserInput::turn()};
    if (ch == 'q')
    {
      std::cout << "\n\nBye!\n\n";
      return 0;
    }
    Direction direction{UserInput::getDirection(ch)};
    std::cout << "You entered direction: " << direction << '\n';
    if (board.moveTile(direction))
    {
      std::cout << board;
      if (board.isWon())
      {
        std::cout << "\n\nYou won!\n\n";
        return 0;
      }
    }
  }

  return 0;
}
