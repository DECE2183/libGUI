#pragma once

#include <Utils/GDisplay.hpp>
#include <Adafruit_GFX.h>
#include "AdafruitGFXGenericColor.hpp"

class AdafruitGFXGenericDisplay : public GDisplay
{
protected:
  Adafruit_GFX *_display;

  uint16_t convertColor(GColor &color) const
  {
    return ((AdafruitGFXGenericColor *)&color)->convert();
  }

public:
  AdafruitGFXGenericDisplay(Adafruit_GFX &display) : GDisplay()
  {
    _display = &display;
  }

  AdafruitGFXGenericDisplay(Adafruit_GFX *display) : GDisplay()
  {
    _display = display;
  }

  // Draw pixel at X and Y coords
  void drawPixel(int x, int y, GColor color)
  {
    _display->drawPixel(x, y, convertColor(color));
  }

  // Fill the entire display with a specific color
  void fill(GColor color = GColor())
  {
    _display->fillScreen(convertColor(color));
  }

  // Draw horizontal line
  void drawHLine(int x, int y, int width, GColor color)
  {
    _display->drawFastHLine(x, y, width, convertColor(color));
  }
  // Draw vertical line
  void drawVLine(int x, int y, int height, GColor color)
  {
    _display->drawFastVLine(x, y, height, convertColor(color));
  }
  // Draw line
  void drawLine(int xStart, int yStart, int xEnd, int yEnd, GColor color)
  {
    _display->drawLine(xStart, yStart, xEnd, yEnd, convertColor(color));
  }

  // Draw rectangle
  void drawRect(int x, int y, int xSize, int ySize, GColor color)
  {
    _display->fillRect(x, y, xSize, ySize, convertColor(color));
  }

  // Get display resolution
  iVector2 getSize() const
  {
    return iVector2(_display->width(), _display->height());
  }
};
