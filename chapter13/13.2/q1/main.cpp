#include <iostream>

class IntPair
{
public:
  int m_x{};
  int m_y{};

  void set(int x, int y)
  {
    m_x = x;
    m_y = y;
  }

  void print()
  {
    std::cout << "Pair:(" << m_x << ", " << m_y << ")\n";
  }
};

int main()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2 { 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
}
