#include <iostream>
#include <cmath>

class Point2d
{
private:
  double m_x{};
  double m_y{};

public:
  Point2d(double x = 0.0, double y = 0.0) : m_x{x}, m_y{y}
  {
  }

  void print()
  {
    std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
  }

  // q1b - leaving here and adding q1c below as they are named differently
  double distanceTo(const Point2d &p)
  {
    return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
  }

  friend double distanceFrom(const Point2d &p1, const Point2d &p2);
};

// q1c
double distanceFrom(const Point2d &p1, const Point2d &p2)
{
  return std::sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) + (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y));
}

int main()
{
  Point2d first{};
  Point2d second{3.0, 4.0};
  first.print();
  second.print();
  std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
  std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

  return 0;
}
