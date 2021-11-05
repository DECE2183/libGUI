#pragma once

#include "Vector.hpp"
#include "GColor.hpp"
#include "GFont.hpp"

class GDisplay
{
public:
  GDisplay();

  // Draw pixel at X and Y coords
  virtual void drawPixel(int x, int y, GColor color) = 0;
  // Draw pixel at a specific pos
  void drawPixel(iVector2 pos, GColor color)
  {
    drawPixel(pos.x, pos.y, color);
  }

  // Fill the entire display with a specific color
  virtual void fill(GColor color = GColor());

  // Draw horizontal line
  virtual void drawHLine(int x, int y, int width, GColor color);
  // Draw vertical line
  virtual void drawVLine(int x, int y, int height, GColor color);
  // Draw line
  virtual void drawLine(int xStart, int yStart, int xEnd, int yEnd, GColor color);
  // Draw line
  void drawLine(iVector2 posStart, iVector2 posEnd, GColor color)
  {
    drawLine(posStart.x, posStart.y, posEnd.x, posEnd.y, color);
  }

  // Draw rectangle
  virtual void drawRect(int x, int y, int xSize, int ySize, GColor color);
  // Draw rectangle
  void drawRect(iVector2 pos, iVector2 size, GColor color)
  {
    drawRect(pos.x, pos.y, size.x, size.y, color);
  }

  // Draw char at a specific pos with a specific font
  virtual void drawChar(iVector2 pos, char ch, GColor color, const GFont *font);
  // Draw char at a specific pos with a specific font
  void drawChar(iVector2 pos, char ch, GColor color, const GFont &font)
  {
    drawChar(pos, ch, color, &font);
  }

  // Get display resolution
  virtual iVector2 getSize() const;
};
