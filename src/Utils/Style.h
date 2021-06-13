#pragma once
typedef unsigned char Color;

enum State
{
  Normal,
  Hover,
  Pressed,
  EnumSize,
};

struct Style
{
  Style(Color background, Color foreground, Color border)
  {
    backgroundColor = background;
    foregroundColor = foreground;
    borderColor = border;
  }

  void setBorderThickness(unsigned char ltrb)
  {
    borderThickness[0] = ltrb;
    borderThickness[1] = ltrb;
    borderThickness[2] = ltrb;
    borderThickness[3] = ltrb;
  }

  void setBorderThickness(unsigned char lr, unsigned char tb)
  {
    borderThickness[0] = lr;
    borderThickness[1] = tb;
    borderThickness[2] = lr;
    borderThickness[3] = tb;
  }

  void setBorderThickness(unsigned char l, unsigned char t, unsigned char r, unsigned char b)
  {
    borderThickness[0] = l;
    borderThickness[1] = t;
    borderThickness[2] = r;
    borderThickness[3] = b;
  }

  Color backgroundColor = 0x60;
  Color foregroundColor = 0x00;
  Color borderColor = 0x00;
  unsigned char borderThickness[4] = {1, 1, 1, 1};
};
