#pragma once
typedef unsigned char Color;

#include "GFont.h"
#include "../Fonts/DefaultFont.h"

enum State
{
  Normal,
  Hover,
  Pressed,
  EnumSize,
};

enum Alignment
{
  Left,
  Center,
  Right,
  Top,
  Bottom,
};

struct Style
{
  Style(Color background, Color foreground, Color border, const GFont &f = DefaultFont)
  {
    backgroundColor = background;
    foregroundColor = foreground;
    borderColor = border;
    font = &f;
  }

  Style(Color background, Color foreground, Color border, unsigned char ltrb) : Style(background, foreground, border)
  {
    setBorderThickness(ltrb);
  }
  Style(Color background, Color foreground, Color border, unsigned char lr, unsigned char tb) : Style(background, foreground, border)
  {
    setBorderThickness(lr, tb);
  }
  Style(Color background, Color foreground, Color border, unsigned char l, unsigned char t, unsigned char r, unsigned char b) : Style(background, foreground, border)
  {
    setBorderThickness(l, t, r, b);
  }


  Style(Color background, Color foreground, Color border, const GFont &f, unsigned char ltrb) : Style(background, foreground, border, f)
  {
    setBorderThickness(ltrb);
  }
  Style(Color background, Color foreground, Color border, const GFont &f, unsigned char lr, unsigned char tb) : Style(background, foreground, border, f)
  {
    setBorderThickness(lr, tb);
  }
  Style(Color background, Color foreground, Color border, const GFont &f, unsigned char l, unsigned char t, unsigned char r, unsigned char b) : Style(background, foreground, border, f)
  {
    setBorderThickness(l, t, r, b);
  }


  Style(Color background, Color foreground, Color border, Alignment hAlign, Alignment vAlign = Center) : Style(background, foreground, border)
  {
    horizontalAlignment = hAlign;
    verticalAlignment = vAlign;
  }
  Style(Color background, Color foreground, Color border, unsigned char ltrb, Alignment hAlign, Alignment vAlign = Center) : Style(background, foreground, border, hAlign, vAlign)
  {
    setBorderThickness(ltrb);
  }
  Style(Color background, Color foreground, Color border, unsigned char lr, unsigned char tb, Alignment hAlign, Alignment vAlign = Center) : Style(background, foreground, border, hAlign, vAlign)
  {
    setBorderThickness(lr, tb);
  }
  Style(Color background, Color foreground, Color border, unsigned char l, unsigned char t, unsigned char r, unsigned char b, Alignment hAlign, Alignment vAlign = Center) : Style(background, foreground, border, hAlign, vAlign)
  {
    setBorderThickness(l, t, r, b);
  }


  Style(Color background, Color foreground, Color border, const GFont &f, Alignment hAlign, Alignment vAlign = Center) : Style(background, foreground, border, f)
  {
    horizontalAlignment = hAlign;
    verticalAlignment = vAlign;
  }
  Style(Color background, Color foreground, Color border, unsigned char ltrb, const GFont &f, Alignment hAlign, Alignment vAlign = Center) : Style(background, foreground, border, f, hAlign, vAlign)
  {
    setBorderThickness(ltrb);
  }
  Style(Color background, Color foreground, Color border, unsigned char lr, unsigned char tb, const GFont &f, Alignment hAlign, Alignment vAlign = Center) : Style(background, foreground, border, f, hAlign, vAlign)
  {
    setBorderThickness(lr, tb);
  }
  Style(Color background, Color foreground, Color border, unsigned char l, unsigned char t, unsigned char r, unsigned char b, const GFont &f, Alignment hAlign, Alignment vAlign = Center) : Style(background, foreground, border, f, hAlign, vAlign)
  {
    setBorderThickness(l, t, r, b);
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

  void setFont(GFont &f)
  {
    font = &f;
  }
  const GFont *getFont() const
  {
    return font;
  }

  Color backgroundColor = 0x60;
  Color foregroundColor = 0x00;
  Color borderColor = 0x00;
  unsigned char borderThickness[4] = {1, 1, 1, 1};

  Alignment horizontalAlignment = Left;
  Alignment verticalAlignment = Center;

  const GFont *font;
};
