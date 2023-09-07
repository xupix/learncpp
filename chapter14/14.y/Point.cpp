#include "Point.h"

Point::Point(int x, int y) : m_x{x}, m_y{y}
{
}

Point Point::getAdjacentPoint(Direction direction) const
{
  switch (direction.getDirection())
  {
  case Direction::up:
    return Point{m_x - 1, m_y};
  case Direction::down:
    return Point{m_x + 1, m_y};
  case Direction::left:
    return Point{m_x, m_y - 1};
  case Direction::right:
    return Point{m_x, m_y + 1};

  default:
    std::cout << "Unknown direction";
    return *this;
  }
}

bool operator==(Point p1, Point p2)
{
  return ((p1.m_x == p2.m_x) && (p1.m_y == p2.m_y));
}

bool operator!=(Point p1, Point p2)
{
  return !(p1 == p2);
}

// Point class test code
// int main()
// {
//   std::cout << std::boolalpha;
//   std::cout << (Point{1, 1}.getAdjacentPoint(Direction::up) == Point{1, 0}) << '\n';
//   std::cout << (Point{1, 1}.getAdjacentPoint(Direction::down) == Point{1, 2}) << '\n';
//   std::cout << (Point{1, 1}.getAdjacentPoint(Direction::left) == Point{0, 1}) << '\n';
//   std::cout << (Point{1, 1}.getAdjacentPoint(Direction::right) == Point{2, 1}) << '\n';
//   std::cout << (Point{1, 1} != Point{2, 1}) << '\n';
//   std::cout << (Point{1, 1} != Point{1, 2}) << '\n';
//   std::cout << !(Point{1, 1} != Point{1, 1}) << '\n';

//   return 0;
// }
