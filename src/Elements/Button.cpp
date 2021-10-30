#include "Button.h"

//================= CONSTRUCTOR ===================//
Button::Button(iVector2 pos, iVector2 size, const char *text, GUIElement *parent, StyleSheet *style) :
    Section(pos, size, parent, style),
    _label(iVector2(0), size, text, this, style)
{
  _styles = style;
  container = false;
}
Button::Button(iVector2 pos, iVector2 size, const char *text, GUIElement &parent, StyleSheet &style) :
    Section(pos, size, &parent, &style),
    _label(iVector2(0), size, text, this, &style)
{
  _styles = &style;
  container = false;
}

Button::Button(const Button &from) : Section(from),
    _label(iVector2(0, 0), from._label.getSize(), from._label.getPureText(), this, from._label.getStyle())
{
  _label.autorender = from._label.autorender;
}

//================= PUBLIC ===================//
void Button::render()
{
  if (GUIManager::canRender() != true || _visible == false)
    return;

  renderBackground();
  _label.render();
  renderBorders();
}

void Button::setState(State state)
{
  _label.setState(state);
  GUIElement::setState(state);
}