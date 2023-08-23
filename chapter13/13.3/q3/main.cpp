#include <iostream>
#include <array>
#include <cassert>

class Stack
{
private:
  std::array<int, 10> m_array{ };
  int m_size{ 0 };

public:
  void reset()
  {
    m_size = 0;
  }

  bool push(int a)
  {
    if(m_array.size() != m_size)
    {
      m_array[m_size] = a;
      ++m_size;
      return true;
    }
    return false;
  }

  int pop()
  {
    assert(m_size > 0 && "Stack is empty; can't pop()");

    --m_size;
    return m_array[m_size];
  }

  void print()
  {
    std::cout << "( ";
    // for (auto element : m_array)
    for (int i{ 0 }; i < m_size; ++i)
    {
      std::cout << m_array[i] << ' ';
    }

    std::cout << ")\n";
  }
};

int main()
{
	Stack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
