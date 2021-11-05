#pragma once

#include <stdint.h>

struct GColor
{
protected:
  uint32_t _color;

public:
  GColor(uint32_t hex = 0xFF000000);
  GColor(uint8_t r, uint8_t g, uint8_t b);
  GColor(uint16_t h, uint8_t s, uint8_t v);

  // Create new color from RGB
  static GColor fromRGB(uint8_t r, uint8_t g, uint8_t b);
  // Create new color from HSV
  static GColor fromHSV(uint16_t h, uint8_t s, uint8_t v);

  //===============
  // Alpha Control
  //===============

  // Get Alpha component
  virtual uint8_t A() const;
  // Set Alpha component
  virtual void A(uint8_t alpha);


  //===============
  //  RGB Control
  //===============

  // Get Red component
  virtual uint8_t R() const;
  // Get Green component
  virtual uint8_t G() const;
  // Get Blue component
  virtual uint8_t B() const;

  // Set color in RGB format
  virtual void RGB(uint8_t r, uint8_t g, uint8_t b);
  // Set Red component
  virtual void R(uint8_t r);
  // Set Green component
  virtual void G(uint8_t g);
  // Set Blue component
  virtual void B(uint8_t b);


  //===============
  //  HSV Control
  //===============

  // Get HUE
  virtual uint16_t H() const;
  // Get Saturation
  virtual uint8_t S() const;
  // Get Value
  virtual uint8_t V() const;

  // Set color in HSV format
  virtual void HSV(uint16_t h, uint8_t s, uint8_t v);
  // Set HUE
  virtual void H(uint16_t h);
  // Set Saturation
  virtual void S(uint8_t s);
  // Set Value
  virtual void V(uint8_t v);
};
