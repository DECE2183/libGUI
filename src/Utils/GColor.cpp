#include "GColor.hpp"

GColor::GColor(uint32_t hex)
{
  if (hex > 0xFFFFFF)
  {
    _color = hex;
  }
  else
  {
    _color &= 0xFF000000;
    _color |= hex;
  }
}

GColor::GColor(uint8_t r, uint8_t g, uint8_t b)
{
  RGB(r, g, b);
}

GColor::GColor(uint16_t h, uint8_t s, uint8_t v)
{
  HSV(h, s, v);
}

// Create new color from RGB
GColor GColor::fromRGB(uint8_t r, uint8_t g, uint8_t b)
{
  return GColor(r, g, b);
}
// Create new color from HSV
GColor GColor::fromHSV(uint16_t h, uint8_t s, uint8_t v)
{
  return GColor(h, s, v);
}

// Get Alpha component
uint8_t GColor::A() const
{
  return (uint8_t)(_color >> 24);
}
// Set Alpha component
void GColor::A(uint8_t alpha)
{
  _color &= 0x00FFFFFF;
  _color |= alpha;
}

// Get Red component
uint8_t GColor::R() const
{
  return (uint8_t)((_color >> 16) & 0xFF);
}
// Get Green component
uint8_t GColor::G() const
{
  return (uint8_t)((_color >> 8) & 0xFF);
}
// Get Blue component
uint8_t GColor::B() const
{
  return (uint8_t)(_color & 0xFF);
}

// Set color in RGB format
void GColor::RGB(uint8_t r, uint8_t g, uint8_t b)
{
  _color &= 0xFF000000;
  _color |= ((uint32_t)r << 16) | ((uint32_t)g << 8) | ((uint32_t)b);
}
// Set Red component
void GColor::R(uint8_t r)
{
  _color &= 0xFF00FFFF;
  _color |= ((uint32_t)r << 16);
}
// Set Green component
void GColor::G(uint8_t g)
{
  _color &= 0xFFFF00FF;
  _color |= ((uint32_t)g << 8);
}
// Set Blue component
void GColor::B(uint8_t b)
{
  _color &= 0xFFFFFF00;
  _color |= ((uint32_t)b);
}

// Get HUE
uint16_t GColor::H() const
{

}
// Get Saturation
uint8_t GColor::S() const
{

}
// Get Value
uint8_t GColor::V() const
{

}

// Set color in HSV format
void GColor::HSV(uint16_t h, uint8_t s, uint8_t v)
{

}
// Set HUE
void GColor::H(uint16_t h)
{

}
// Set Saturation
void GColor::S(uint8_t s)
{

}
// Set Value
void GColor::V(uint8_t v)
{
  
}
