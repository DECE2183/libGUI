#pragma once
#include "GUIElement.h"
#include "../GUIManager.h"

class Section : public GUIElement
{
public:
  typedef unsigned char Color;

  Section(iVector2 pos, iVector2 size);
  Section(iVector2 pos, iVector2 size, GUIElement *parent);

  virtual void render();

protected:
  Color _backgroundColor;
  Color _foregroundColor;
  Color _borderColor;

  uint8_t _borderThickness[4] = {1, 1, 1, 1};
};