#ifndef POINT_H
#define POINT_H

#include "Direction.h"

class Point
{
public:
  Point(int x, int y);

  Point getAdjacentPoint(Direction direction) const;

  int getX() { return m_x; };
  int getY() { return m_y; };
  friend bool operator==(Point p1, Point p2);
  friend bool operator!=(Point p1, Point p2);

private:
  int m_x{};
  int m_y{};
};

#endif
