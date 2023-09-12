#include "Tile.h"
#include <iostream>

Tile::Tile() = default;
Tile::Tile(int num) : m_num{num}
{
}

bool Tile::isEmpty() const
{
  return m_num == 0;
}

int Tile::getNum() const
{
  return m_num;
}

std::ostream &operator<<(std::ostream &ostr, Tile tile)
{
  if (tile.m_num > 9)
  {
    ostr << ' ' << tile.m_num << ' ';
  }
  else if (tile.m_num > 0)
  {
    ostr << "  " << tile.m_num << ' ';
  }
  else if (tile.isEmpty())
  {
    ostr << "    ";
  }

  return ostr;
}

// test code for Tile class
// int main()
// {
//   Tile tile1{10};
//   Tile tile2{8};
//   Tile tile3{0}; // the missing tile
//   Tile tile4{1};

//   std::cout << "0123456789ABCDEF\n"; // to make it easy to see how many spaces are in the next line
//   std::cout << tile1 << tile2 << tile3 << tile4 << '\n';

//   std::cout << std::boolalpha << tile1.isEmpty() << ' ' << tile3.isEmpty() << '\n';
//   std::cout << "Tile 2 has number: " << tile2.getNum() << "\nTile 4 has number: " << tile4.getNum() << '\n';

//   return 0;
// }
