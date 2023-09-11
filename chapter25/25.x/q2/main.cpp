#include "Circle.h"
#include "Point.h"
#include "Triangle.h"

#include <vector>
#include <iostream>

// q2b test code
// int main()
// {
//   Circle c{Point{1, 2}, 7};
//   std::cout << c << '\n';

//   Triangle t{Point{1, 2}, Point{3, 4}, Point{5, 6}};
//   std::cout << t << '\n';

//   return 0;
// }

// q2c solution

int getLargestRadius(std::vector<Shape *> v)
{
  int max_r{0};
  for (const auto *shape : v)
  {
    if (auto *c{dynamic_cast<const Circle *>(shape)})
    {
      max_r = std::max(c->getRadius(), max_r);
    }
  }

  return max_r;
}

int main()
{
  std::vector<Shape *> v{
      new Circle{Point{1, 2}, 7},
      new Triangle{Point{1, 2}, Point{3, 4}, Point{5, 6}},
      new Circle{Point{7, 8}, 3}};

  // print each shape in vector v on its own line here
  for (const auto *shape : v)
    std::cout << *shape << '\n';

  std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

  // delete each element in the vector here
  for (const auto *shape : v)
    delete shape;

  return 0;
}
