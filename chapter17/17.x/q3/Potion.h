#ifndef POTION_H
#define POTION_H

#include "Random.h"

#include <array>
#include <string_view>

class Potion
{
public:
  enum class Type
  {
    health,
    strength,
    poison,

    max_types,
  };

  enum class Size
  {
    small,
    medium,
    large,

    max_sizes,
  };

  Potion() : m_type{getRandomType()}, m_size{getRandomSize()}
  {
  }

  static Potion getRandomPotion();
  std::string getName() const;
  Type getType() const;
  Size getSize() const;

private:
  Type m_type{};
  Size m_size{};

  Type getRandomType() const;
  Size getRandomSize() const;
};

#endif
