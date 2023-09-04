#include <iostream>
#include <numeric>

class Fraction
{
private:
  int m_numerator{0};
  int m_denominator{1};

public:
  Fraction() = default;

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

  friend std::ostream &operator<<(std::ostream &out, const Fraction &frac);
  friend std::istream &operator>>(std::istream &in, Fraction &frac);
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

std::ostream &operator<<(std::ostream &out, const Fraction &frac)
{
  out << frac.m_numerator << '/' << frac.m_denominator;

  return out;
}

std::istream &operator>>(std::istream &in, Fraction &frac)
{
  in >> frac.m_numerator;
  in.ignore(std::numeric_limits<std::streamsize>::max(), '/');
  in >> frac.m_denominator;
  frac.reduce();

  return in;
}

int main()
{
  Fraction f1;
  std::cout << "Enter fraction 1: ";
  std::cin >> f1;

  Fraction f2;
  std::cout << "Enter fraction 2: ";
  std::cin >> f2;

  std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

  return 0;
}
