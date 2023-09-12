#include <iostream>
#include <cassert>
#include <algorithm>

class IntArray
{
private:
  std::size_t m_size{};
  int *m_array{};

public:
  IntArray(int size = 0)
      : m_size{static_cast<std::size_t>(size)}, m_array{m_size && m_size > 0 ? new int[m_size] : nullptr}
  {
  }

  // copy constructor
  IntArray(const IntArray &other)
      : m_size{other.m_size}, m_array{m_size ? new int[m_size] : nullptr}
  {
    std::copy(other.m_array, other.m_array + m_size, m_array);
  }

  ~IntArray()
  {
    delete[] m_array;
  }

  int &operator[](int index)
  {
    assert(index >= 0 && index < static_cast<int>(m_size));

    return m_array[index];
  }

  int operator[](int index) const
  {
    assert(index >= 0 && index < m_size);

    return m_array[index];
  }

  IntArray &operator=(IntArray other)
  {
    swap(*this, other);

    return *this;
  }

  friend std::ostream &operator<<(std::ostream &ostr, IntArray intArray)
  {
    for (int i{0}; i < intArray.m_size; ++i)
    {
      ostr << intArray.m_array[i] << ' ';
    }
    return ostr;
  }

  friend void swap(IntArray &array1, IntArray &array2)
  {
    using std::swap;

    swap(array1.m_size, array2.m_size);
    swap(array1.m_array, array2.m_array);
  }
};

IntArray fillArray()
{
  IntArray a(5);

  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;

  return a;
}

int main()
{
  IntArray a{fillArray()};

  std::cout << a << '\n';

  auto &ref{a}; // we're using this reference to avoid compiler self-assignment errors
  a = ref;

  IntArray b(1);
  b = a;

  a[4] = 7;

  std::cout << b << '\n';

  return 0;
}
