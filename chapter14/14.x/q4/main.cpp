#include <iostream>
#include <cstdint>
#include <cmath>

class FixedPoint2
{
private:
  int16_t m_num{};
  int8_t m_frac{};

public:
  FixedPoint2()
  {
  }

  FixedPoint2(int16_t num = 0, int8_t frac = 0) : m_num{num}, m_frac{frac}
  {
    if (m_num < 0 || m_frac < 0)
    {
      if (m_num > 0)
      {
        m_num = -m_num;
      }
      if (m_frac > 0)
      {
        m_frac = -m_frac;
      }
    }
  }

  FixedPoint2(double dbl)
      : m_num{static_cast<int16_t>(std::trunc(dbl))}, m_frac{static_cast<int8_t>(std::round((dbl - m_num) * 100))}
  {
  }

  operator double() const
  {
    return m_num + (static_cast<double>(m_frac) / 100);
  }

  bool operator==(const FixedPoint2 &fp)
  {
    return ((m_num == fp.m_num) && (m_frac == fp.m_frac));
  }

  void operator-(FixedPoint2 fp)
  {
    if (m_num > 0)
    {
      m_num = -m_num;
    }
    if (m_frac > 0)
    {
      m_frac = -m_frac;
    }
  }

  friend std::ostream &operator<<(std::ostream &ostr, FixedPoint2 &fp)
  {
    ostr << static_cast<double>(fp);

    return ostr;
  }

  friend std::istream &operator>>(std::istream &istr, FixedPoint2 &fp)
  {
    double num;
    istr >> num;
    fp = FixedPoint2{num};

    return istr;
  }

  friend FixedPoint2 operator+(const FixedPoint2 &fp1, const FixedPoint2 &fp2)
  {
    return FixedPoint2{(static_cast<double>(fp1) + static_cast<double>(fp2))};
  }
};

void testAddition()
{
  // h/t to reader Sharjeel Safdar for this function
  std::cout << std::boolalpha;
  std::cout << (FixedPoint2{0.75} + FixedPoint2{1.23} == FixedPoint2{1.98}) << '\n';    // both positive, no decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{1.50} == FixedPoint2{2.25}) << '\n';    // both positive, with decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.23} == FixedPoint2{-1.98}) << '\n'; // both negative, no decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{-1.50} == FixedPoint2{-2.25}) << '\n'; // both negative, with decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.23} == FixedPoint2{-0.48}) << '\n';  // second negative, no decimal overflow
  std::cout << (FixedPoint2{0.75} + FixedPoint2{-1.50} == FixedPoint2{-0.75}) << '\n';  // second negative, possible decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.23} == FixedPoint2{0.48}) << '\n';   // first negative, no decimal overflow
  std::cout << (FixedPoint2{-0.75} + FixedPoint2{1.50} == FixedPoint2{0.75}) << '\n';   // first negative, possible decimal overflow
}

int main()
{
  // q4b
  // FixedPoint2 a{34, 56};
  // std::cout << a << '\n';

  // FixedPoint2 b{-2, 8};
  // std::cout << b << '\n';

  // FixedPoint2 c{2, -8};
  // std::cout << c << '\n';

  // FixedPoint2 d{-2, -8};
  // std::cout << d << '\n';

  // FixedPoint2 e{0, -5};
  // std::cout << e << '\n';

  // std::cout << static_cast<double>(e) << '\n';

  // q4c
  // Handle cases where the argument is representable directly
  // FixedPoint2 a{0.01};
  // std::cout << a << '\n';

  // FixedPoint2 b{-0.01};
  // std::cout << b << '\n';

  // // Handle cases where the argument has some rounding error
  // FixedPoint2 c{5.01}; // stored as 5.0099999... so we'll need to round this
  // std::cout << c << '\n';

  // FixedPoint2 d{-5.01}; // stored as -5.0099999... so we'll need to round this
  // std::cout << d << '\n';

  // // // Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
  // FixedPoint2 e{106.9978}; // should be stored with base 107 and decimal 0
  // std::cout << e << '\n';

  // FixedPoint2 f{1.9}; // make sure we handle single digit decimal
  // std::cout << f;

  // q4d
  testAddition();

  FixedPoint2 a{-0.48};
  std::cout << a << '\n';

  std::cout << -a << '\n';

  std::cout << "Enter a number: "; // enter 5.678
  std::cin >> a;

  std::cout << "You entered: " << a << '\n';

  return 0;
}
