#include <iostream>
#include <cstdint>

using colorElem = std::uint8_t;

class RGBA
{
private:
  colorElem m_red{};
  colorElem m_green{};
  colorElem m_blue{};
  colorElem m_alpha{};

public:
  RGBA(colorElem red = 0, colorElem green = 0, colorElem blue = 0, colorElem alpha = 255)
      : m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha}
  {
  }

  void print()
  {
    std::cout << "r=" << static_cast<int>(m_red) << " g="
              << static_cast<int>(m_green) << " b=" << static_cast<int>(m_blue)
              << " a=" << static_cast<int>(m_alpha) << '\n';
  }
};

int main()
{
  RGBA teal{0, 127, 127};
  teal.print();

  return 0;
}
