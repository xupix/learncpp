#include "Direction.h"
#include "Random.h"

#include <cassert>

Direction::Direction(Type type) : m_direction{type}
{
}

Direction Direction::operator-() const
{
  switch (m_direction)
  {
  case up:
    return Direction{down};
  case down:
    return Direction{up};
  case left:
    return Direction{right};
  case right:
    return Direction{left};
  case max_direction:
  default:
    assert(0 && "Wrong direction in operator-");
  }

  assert(0 && "Wrong direction in operator-");
  return Direction{up};
}

Direction Direction::getRandomDirection()
{
  return Direction{Type{static_cast<Type>(Random::get(0, Type::max_direction - 1))}};
}

std::ostream &operator<<(std::ostream &ostr, Direction direction)
{
  switch (direction.getDirection())
  {
  case Direction::up:
    return ostr << "up";
  case Direction::down:
    return ostr << "down";
  case Direction::left:
    return ostr << "left";
  case Direction::right:
    return ostr << "right";

  default:
    return ostr << "Wrong direction in operator<<";
  }
}
