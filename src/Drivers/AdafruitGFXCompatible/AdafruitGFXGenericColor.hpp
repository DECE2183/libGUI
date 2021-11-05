#pragma once

#include <Utils/GColor.hpp>

class AdafruitGFXGenericColor : public GColor
{
public:
  AdafruitGFXGenericColor(uint32_t hex = 0xFF000000) : GColor(hex) {}
  AdafruitGFXGenericColor(uint8_t r, uint8_t g, uint8_t b) : GColor(r, g, b) {}
  AdafruitGFXGenericColor(uint16_t h, uint8_t s, uint8_t v) : GColor(h, s, v) {}

  uint16_t convert()
  {
    uint16_t new_color = 0;

    // Apply red component
    new_color |= ((uint16_t)((_color >> 19) & 0x1F) << 11);
    // Apply green component
    new_color |= ((uint16_t)((_color >> 10) & 0x3F) << 5);
    // Apply blue component
    new_color |= ((uint16_t)((_color >> 3) & 0x1F));

    return new_color;
  }
};
