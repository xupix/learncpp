#include <iostream>

template <typename T, typename U, typename V>
class Triad
{
private:
  T m_first{};
  U m_second{};
  V m_third{};

public:
  Triad(const T first, const U second, const V third) : m_first{first}, m_second{second}, m_third{third}
  {
  }

  T getFirst() const { return m_first; }
  U getSecond() const { return m_second; }
  V getThird() const { return m_third; }
  void setFirst(const T first) { m_first = first; }
  void setSecond(const U second) { m_second = second; }
  void setThird(const V third) { m_third = third; }

  void print();
};

template <typename T, typename U, typename V>
void Triad<T, U, V>::print()
{
  std::cout << '[' << m_first << ", " << m_second << ", " << m_third << ']';
}

int main()
{
  Triad t1{1, 2, 3};
  t1.print();

  Triad t2{1, 2.3, "Hello"};
  t2.print();

  return 0;
}
