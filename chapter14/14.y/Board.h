#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include "Direction.h"
#include "Point.h"

#include <iostream>
#include <array>

// Increase amount of new lines if your board isn't
// at the very bottom of the console
constexpr int g_consoleLines{25};

// Your code goes here
class Board
{
public:
  Board();
  auto operator[](int index) const;
  bool moveTile(const Direction &direction);
  bool isWon();
  void initialize();
  static void printEmptyLines(int num);
  friend bool operator==(const Board &b1, const Board &b2);
  friend std::ostream &operator<<(std::ostream &ostr, Board board);

private:
  static constexpr int SIZE = 4;
  std::array<std::array<Tile, SIZE>, SIZE> m_board{};

  Point findEmptyTile();
  void swap(Point emptyP, Point adjacentP);
  bool isValidPosition(Point &p);
};

#endif
