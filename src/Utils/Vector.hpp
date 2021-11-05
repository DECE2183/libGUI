#pragma once

#include <math.h>

template<typename number> class Vector2
{
public:
  number x;
  number y;

  Vector2(number v = 0)
  {
    x = v;
    y = v;
  }

  Vector2(number _x, number _y)
  {
    x = _x;
    y = _y;
  }

  Vector2<number> operator*(number s) const
  {
    return Vector2(x * s, y * s);
  }

  Vector2<number> &operator*=(number s)
  {
    *this = *this * s;
    return *this;
  }

  Vector2 &operator+=(number s)
  {
    *this = *this + s;
    return *this;
  }
  Vector2 &operator+=(const Vector2 &v2)
  {
    *this = *this + v2;
    return *this;
  }

  Vector2<number> operator+(const Vector2 &v2) const
  {
    return Vector2(x + v2.x, y + v2.y);
  }

  Vector2<number> operator-(const Vector2 &v2) const
  {
    return Vector2(x - v2.x, y - v2.y);
  }

  Vector2<number> operator-() const
  {
    return Vector2(-x, -y);
  }

  virtual number length() const
  {
    number l2 = x * x + y * y;
    if (!l2)
      return 0.f;
    return (number)sqrt(l2);
  }

  number dot(const Vector2<number> &v2) const
  {
    return x * v2.x + y * v2.y;
  }
};

typedef Vector2<int> iVector2;
typedef Vector2<float> fVector2;
