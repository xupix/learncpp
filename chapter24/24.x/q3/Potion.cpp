#include "Potion.h"

Potion::Type Potion::getRandomType() const
{
  return Potion::Type(static_cast<Type>(Random::get(0, static_cast<int>(Potion::Type::max_types) - 1)));
}

Potion::Size Potion::getRandomSize() const
{
  return Potion::Size(static_cast<Size>(Random::get(0, static_cast<int>(Potion::Size::max_sizes) - 1)));
}

std::string Potion::getName() const
{
  std::string name{};

  switch (Potion::m_size)
  {
  case Size::small:
    name += "Small";
    break;
  case Size::medium:
    name += "Medium";
    break;
  case Size::large:
    name += "Large";
    break;
  case Size::max_sizes:
  default:
    name += "No such potion";
    break;
  }

  name += " potion of ";

  switch (Potion::m_type)
  {
  case Type::health:
    name += "Health";
    break;
  case Type::strength:
    name += "Strength";
    break;
  case Type::poison:
    name += "Posion";
    break;
  case Type::max_types:
  default:
    name += "No such potion";
    break;
  }

  return name;
}

Potion::Type Potion::getType() const
{
  return m_type;
}

Potion::Size Potion::getSize() const
{
  return m_size;
}
