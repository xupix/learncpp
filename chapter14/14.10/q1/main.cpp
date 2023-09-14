#include <iostream>

class Ball
{
public:
  Ball()
  {
    print();
  }

  Ball(std::string_view color) : m_color{color}, m_radius{10.0}
  {
    print();
  }

  Ball(double radius) : m_color{"black"}, m_radius{radius}
  {
    print();
  }

  Ball(std::string_view color, double radius) : m_color{color}, m_radius{radius}
  {
    print();
  }

  void print()
  {
    std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
  }

private:
  std::string m_color{"black"};
  double m_radius{10.0};
};

int main()
{
  Ball def{};
  Ball blue{"blue"};
  Ball twenty{20.0};
  Ball blueTwenty{"blue", 20.0};

  return 0;
}
