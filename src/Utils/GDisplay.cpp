#include "GDisplay.hpp"

#define abs(x) ((x) < 0 ? (x) * -1 : (x))
#define swap(a, b, c) { c = a; a = b; b = c; }

GDisplay::GDisplay() {}

// Fill the entire display with a specific color
void GDisplay::fill(GColor color)
{
  drawRect(iVector2(0, 0), getSize(), color);
}

// Draw horizontal line
void GDisplay::drawHLine(int x, int y, int width, GColor color)
{
  for (unsigned int _x = x; _x < x + width; _x++)
  {
    drawPixel(_x, y, color);
  }
}
// Draw vertical line
void GDisplay::drawVLine(int x, int y, int height, GColor color)
{
  for (unsigned int _y = y; _y < y + height; _y++)
  {
    drawPixel(x, _y, color);
  }
}
// Draw line
void GDisplay::drawLine(int xStart, int yStart, int xEnd, int yEnd, GColor color)
{
  int steep = abs(yEnd - yStart) > abs(xEnd - xStart);
  int swap_val;

  if (steep)
  {
    swap(xStart, xEnd, swap_val);
    swap(yStart, yEnd, swap_val);
  }

  if (xStart > xEnd)
  {
    swap(xStart, xEnd, swap_val);
    swap(yStart, yEnd, swap_val);
  }

  int16_t dx, dy;
  dx = xEnd - xStart;
  dy = abs(yEnd - yStart);

  int16_t err = dx / 2;
  int16_t ystep;

  if (yStart < yEnd)
  {
    ystep = 1;
  }
  else
  {
    ystep = -1;
  }

  for (; xStart <= xEnd; xStart++)
  {
    if (steep)
    {
      drawPixel(yStart, xStart, color);
    }
    else
    {
      drawPixel(xStart, yStart, color);
    }
    err -= dy;
    if (err < 0)
    {
      yStart += ystep;
      err += dx;
    }
  }
}

// Draw rectangle
void GDisplay::drawRect(int x, int y, int xSize, int ySize, GColor color)
{
  for (unsigned int _x = x; _x < x + xSize; _x++)
  {
    drawVLine(_x, y, ySize, color);
  }
}

// Draw char at a specific pos with a specific font
void GDisplay::drawChar(iVector2 pos, char ch, GColor color, const GFont *font)
{
  unsigned int chH = font->getHeight();
  unsigned int bRow = font->getBytesPerRow();

  const unsigned char *chPix = font->getPixels() + (ch - font->getFirstChar()) * (chH * bRow);

  for (unsigned int row = 0; row < chH; row++)
  {
    for (unsigned char x = 0; x < 8; x++)
    {
      for (unsigned char b = 0; b < bRow; b++)
      {
        if (chPix[row * bRow + b] & (0b10000000U >> x))
          drawPixel(pos.x + x + b * 8, pos.y + row, color);
      }
    }
  }
}

// Get display resolution
iVector2 GDisplay::getSize() const { return iVector2(0, 0); }
