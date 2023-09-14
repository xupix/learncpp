#include <iostream>

class Ball
{
public:
  Ball(std::string_view color, double radius) : m_color{color}, m_radius{radius}
  {
  }

  void print()
  {
    std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
  }

private:
  std::string m_color{};
  double m_radius{};
};

int main()
{
  Ball blue{"blue", 10.0};
  blue.print();

  Ball red{"red", 12.0};
  red.print();

  return 0;
}
