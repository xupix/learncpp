#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "Point.h"

#include <iostream>

class Triangle : public Shape
{
public:
  Triangle(const Point &x, const Point &y, const Point &z) : m_x{x}, m_y{y}, m_z{z}
  {
  }

  std::ostream &print(std::ostream &out) const override
  {
    out << "Triangle(" << m_x << ", " << m_y << ", " << m_z << ')';
    return out;
  }

private:
  Point m_x;
  Point m_y;
  Point m_z;
};

#endif
