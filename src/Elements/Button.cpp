#include "Button.h"

//================= CONSTRUCTOR ===================//
Button::Button() : Section()
{
  _label.autorender = false;
  container = false;
}

Button::Button(iVector2 pos, iVector2 size, const char *header) : Section(pos, size),
    _label(iVector2(0, 0), iVector2(size.x, size.y), &DefaultButtonStyle, header)
{
  _label.autorender = false;
  _styles = &DefaultButtonStyle;
  container = false;
}
Button::Button(iVector2 pos, iVector2 size, GUIElement *parent, const char *header) : Section(pos, size, parent),
    _label(iVector2(0, 0), iVector2(size.x, size.y), &DefaultButtonStyle, header)
{
  _label.autorender = false;
  _styles = &DefaultButtonStyle;
  container = false;
}
Button::Button(iVector2 pos, iVector2 size, GUIElement &parent, const char *header) : Section(pos, size, &parent),
    _label(iVector2(0, 0), iVector2(size.x, size.y), &DefaultButtonStyle, header)
{
  _label.autorender = false;
  _styles = &DefaultButtonStyle;
  container = false;
}

Button::Button(iVector2 pos, iVector2 size, StyleSheet *style, const char *header) : Section(pos, size, style),
    _label(iVector2(0, 0), iVector2(size.x, size.y), style, header)
{
  _label.autorender = false;
  _styles = style;
  container = false;
}
Button::Button(iVector2 pos, iVector2 size, StyleSheet &style, const char *header) : Section(pos, size, &style),
    _label(iVector2(0, 0), iVector2(size.x, size.y), &style, header)
{
  _label.autorender = false;
  _styles = &style;
  container = false;
}
Button::Button(iVector2 pos, iVector2 size, GUIElement *parent, StyleSheet *style, const char *header) : Section(pos, size, parent, style),
    _label(iVector2(0, 0), iVector2(size.x, size.y), style, header)
{
  _label.autorender = false;
  _styles = style;
  container = false;
}
Button::Button(iVector2 pos, iVector2 size, GUIElement &parent, StyleSheet &style, const char *header) : Section(pos, size, &parent, &style),
    _label(iVector2(0, 0), iVector2(size.x, size.y), &style, header)
{
  _label.autorender = false;
  _styles = &style;
  container = false;
}

Button::Button(const Button &from) : Section(from),
    _label(iVector2(0, 0), from._label.getSize(), from._label.getStyle(), from._label.getPureText())
{
  _label.autorender = from._label.autorender;
  _label.setStyle(from._label.getStyle());
  _styles = from.getStyle();
}

//================= PUBLIC ===================//
void Button::render()
{
  if (GUIManager::canRender() != true || _visible == false)
    return;

  renderBackground();
  renderBorders();
  renderLabel();
}

void Button::setState(State state)
{
  _label.setState(state);
  GUIElement::setState(state);
}

//================= PROTECTED ===================//
void Button::renderLabel()
{
  iVector2 globalPos = getGlobalPosition();
  _label.setPosition(globalPos);
  _label.setSize(_size);
  _label.render();
}

void Button::setUpLabel()
{
  _label.autorender = false;
  for (uint8_t i = 0; i < State::EnumSize; i++)
  {
    _label.setStyle((State)i, _styles->getStyle((State)i));
  }
}