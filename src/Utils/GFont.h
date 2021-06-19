#pragma once

class GFont
{
public:
  const unsigned int width;
  const unsigned int height;
  const unsigned char firstChar;
  const unsigned char lastChar;
  const unsigned int bytesPerRow;

  GFont(unsigned int w, unsigned int h, const unsigned char *pixels, unsigned char firstChar = 32, unsigned char charCount = 95) :
    width(w), height(h),
    firstChar(firstChar), lastChar(firstChar + charCount - 1),
    bytesPerRow((unsigned int)ceil(w / 8.0))
  {
    _pixels = pixels;
  }

  bool isCharValid(char ch) const
  {
    return ch >= firstChar && ch <= lastChar;
  }

  unsigned char getFirstChar() const
  {
    return firstChar;
  }

  unsigned int getWidth() const
  {
    return width;
  }
  unsigned int getHeight() const
  {
    return height;
  }
  unsigned int getBytesPerRow() const
  {
    return bytesPerRow;
  }

  const unsigned char *getPixels() const
  {
    return _pixels;
  }

protected:
  const unsigned char *_pixels;
};