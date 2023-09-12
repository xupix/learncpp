#include <iostream>
#include <cassert>

class MyString
{
private:
  std::string m_str{};

public:
  MyString(std::string str) : m_str{str}
  {
  }

  std::string operator()(int start, int length) const
  {
    assert(start > 0);
    assert(start + length < static_cast<int>(m_str.length()));

    return m_str.substr(static_cast<std::string::size_type>(start),
                        static_cast<std::string::size_type>(length));
  }

  // q3
  std::string_view substr(int start, int length) const
  {
    assert(start > 0);
    assert(start + length < static_cast<int>(m_str.length()));

    return static_cast<std::string_view>(m_str).substr(
        static_cast<std::string_view::size_type>(start),
        static_cast<std::string_view::size_type>(length));
  }

  friend std::ostream &operator<<(std::ostream &out, const MyString &str);
};

std::ostream &operator<<(std::ostream &out, const MyString &str)
{
  out << str.m_str;
  return out;
}

int main()
{
  MyString s{"Hello, world!"};
  std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

  // MyString s { "Hello, world!" };
  std::cout << s.substr(7, 5) << '\n'; // start at index 7 and return 5 characters

  return 0;
}
