#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile
{
public:
  Tile();
  explicit Tile(int num);

  bool isEmpty() const;
  int getNum() const;
  friend std::ostream &operator<<(std::ostream &ostr, Tile tile);

private:
  int m_num{};
};

#endif
