#include "Board.h"

Board::Board()
{
  int tileCount{1};
  for (int i{0}; i < SIZE; ++i)
  {
    for (int j{0}; j < SIZE; ++j)
    {
      m_board[i][j] = Tile{tileCount};
      ++tileCount;
    }
  }
  m_board[SIZE - 1][SIZE - 1] = Tile{0};
}

auto Board::operator[](int index) const
{
  return m_board[index];
}

Point Board::findEmptyTile()
{
  for (int x{0}; x < SIZE; ++x)
    for (int y{0}; y < SIZE; ++y)
      if (m_board[x][y].isEmpty())
        return Point{x, y};

  assert(0 && "No empty tile");
  return Point{-1, -1};
}

void Board::swap(Point emptyP, Point adjacentP)
{
  std::swap(m_board[emptyP.getX()][emptyP.getY()], m_board[adjacentP.getX()][adjacentP.getY()]);
}

bool Board::isValidPosition(Point &p)
{
  return (p.getX() < SIZE && p.getX() >= 0) &&
         (p.getY() < SIZE && p.getY() >= 0);
}

bool Board::moveTile(const Direction &direction)
{
  Point emptyP{findEmptyTile()};
  Point adjacentP{emptyP.getAdjacentPoint(-direction)};
  if (isValidPosition(adjacentP))
  {
    swap(emptyP, adjacentP);
    return true;
  }
  return false;
}

bool Board::isWon()
{
  static Board winningBoard{};
  return winningBoard == *this;
}

void Board::initialize()
{
  int numRandMoves{100}; // set how many moves to randomize for debugging

  for (int i{0}; i < numRandMoves; ++i)
  {
    if (!moveTile(Direction::getRandomDirection()))
      --i;
  }
}

static void printEmptyLines(int num)
{
  for (int i{0}; i < num; ++i)
    std::cout << '\n';
}

bool operator==(const Board &b1, const Board &b2)
{
  for (int x{0}; x < Board::SIZE; ++x)
    for (int y{0}; y < Board::SIZE; ++y)
      if (b1.m_board[x][y].getNum() != b2.m_board[x][y].getNum())
        return false;
  return true;
}

std::ostream &operator<<(std::ostream &ostr, Board board)
{
  printEmptyLines(g_consoleLines);

  for (int i{0}; i < Board::SIZE; ++i)
  {
    for (int j{0}; j < Board::SIZE; ++j)
    {
      ostr << board[i][j];
    }
    ostr << '\n';
  }

  return ostr;
}

// test code for Board class
// int main()
// {
//   Board board{};
//   std::cout << board;

//   return 0;
// }
