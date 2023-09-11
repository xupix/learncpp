#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Point.h"

#include <iostream>

class Circle : public Shape
{
public:
  Circle(const Point &center, int r) : m_center{center}, m_r{r}
  {
  }

  std::ostream &print(std::ostream &out) const override
  {
    out << "Circle(" << m_center << ", raius " << m_r << ')';
    return out;
  }

  int getRadius() const { return m_r; }

private:
  Point m_center;
  int m_r{};
};

#endif
