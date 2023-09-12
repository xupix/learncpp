#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
private:
  std::string m_name{};
  std::string m_color{};

public:
  Fruit(std::string_view name = "", std::string_view color = "") : m_name{name}, m_color{color}
  {
  }

  const std::string &getName() const { return m_name; }
  const std::string &getColor() const { return m_color; }
};

class Apple : public Fruit
{
private:
  double m_fiber{};

public:
  Apple(std::string_view name = "", std::string_view color = "", double fiber = 0.0) : Fruit{name, color}, m_fiber{fiber}
  {
  }

  const double getFiber() const { return m_fiber; };

  friend std::ostream &operator<<(std::ostream &ostr, const Apple &apple)
  {
    ostr << "Apple(" << apple.getName() << ", " << apple.getColor() << ", " << apple.getFiber() << ')';
    return ostr;
  }
};

class Banana : public Fruit
{
public:
  Banana(std::string_view name = "", std::string_view color = "") : Fruit{name, color}
  {
  }

  friend std::ostream &operator<<(std::ostream &ostr, const Banana &banana)
  {
    ostr << "Banana(" << banana.getName() << ", " << banana.getColor() << ')';
    return ostr;
  }
};

int main()
{
  const Apple a{"Red delicious", "red", 4.2};
  std::cout << a << '\n';

  const Banana b{"Cavendish", "yellow"};
  std::cout << b << '\n';

  return 0;
}
