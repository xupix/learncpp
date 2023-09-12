#include <iostream>
#include <numeric>

class Fraction
{
private:
  int m_numerator{0};
  int m_denominator{1};

public:
  Fraction(int numerator, int denominator) : m_numerator{numerator}, m_denominator{denominator}
  {
    reduce();
  }

  void print()
  {
    std::cout << m_numerator << '/' << m_denominator << '\n';
  }

  void reduce()
  {
    int gcd{std::gcd(m_numerator, m_denominator)};
    if (gcd)
    {
      m_numerator /= gcd;
      m_denominator /= gcd;
    }
  }

  friend Fraction operator*(const Fraction &frac, const int num);
  friend Fraction operator*(const int num, const Fraction &frac);
  friend Fraction operator*(const Fraction &frac1, const Fraction &frac2);
};

Fraction operator*(const Fraction &frac, const int num)
{
  return Fraction{frac.m_numerator * num, frac.m_denominator};
}

Fraction operator*(const int num, const Fraction &frac)
{
  return frac * num;
}

Fraction operator*(const Fraction &frac1, const Fraction &frac2)
{
  return Fraction{frac1.m_numerator * frac2.m_numerator, frac1.m_denominator * frac2.m_denominator};
}

int main()
{
  // a)
  // Fraction f1{1, 4};
  // f1.print();

  // Fraction f2{1, 2};
  // f2.print();

  // b)
  Fraction f1{2, 5};
  f1.print();

  Fraction f2{3, 8};
  f2.print();

  Fraction f3{f1 * f2};
  f3.print();

  Fraction f4{f1 * 2};
  f4.print();

  Fraction f5{2 * f2};
  f5.print();

  Fraction f6{Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4}};
  f6.print();

  Fraction f7{0, 6};
  f7.print();

  return 0;
}
