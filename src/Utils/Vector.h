#pragma once

#include <math.h>

template<typename number> class Vector2
{
public:
  number x;
  number y;

  Vector2(number _x = 0, number _y = 0)
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

  Vector2 operator+(const Vector2 &v2) const
  {
    return Vector2(x + v2.x, y + v2.y);
  }

  Vector2 operator-(const Vector2 &v2) const
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


class iVector2 : public Vector2<int>
{
public:
  iVector2()
  {
    x = 0;
    y = 0;
  }
  iVector2(int x, int y) : Vector2<int>(x, y) { ; }

  virtual int length() const
  {
    int l2 = x * x + y * y;
    if (!l2)
      return 0.f;
    return (int)round(sqrt(l2));
  }
};

class fVector2 : public Vector2<float>
{
public:
  fVector2()
  {
    x = 0.0f;
    y = 0.0f;
  }
  fVector2(float x, float y) : Vector2<float>(x, y) { ; }
};
