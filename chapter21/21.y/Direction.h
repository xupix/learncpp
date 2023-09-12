#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>

class Direction
{
public:
  enum Type
  {
    up,
    down,
    left,
    right,

    max_direction,
  };

  Direction(Type type);

  Type getDirection() const { return m_direction; };
  Direction operator-() const;
  static Direction getRandomDirection();

  friend std::ostream &operator<<(std::ostream &ostr, Direction direction);

private:
  Type m_direction{};
};

#endif
