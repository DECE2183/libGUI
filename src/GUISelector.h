#pragma once
#include <Elements/GUIElement.h>

class Selector
{
public:
  Selector(GUIElement *base);
  Selector(GUIElement &base);

  void startClick();
  void endClick();

  void select(GUIElement *element);
  void select(GUIElement &element);
  void next();
  void prev();

  void enter(GUIElement *base);
  void enter(GUIElement &base);
  void enter();

  void back();

  GUIElement *getSelected() const;

protected:
  GUIElement *_base;
  GUIElement *_selectionBase;
  GUIElement *_selectedElement;
};