#include "Label.hpp"

//================= CONSTRUCTOR ===================//
Label::Label(iVector2 pos, iVector2 size, const char *text, GUIElement *parent, StyleSheet *style) : GUIElement(pos, size, parent, style), _text(text)
{
  container = false;
  _selectable = false;
}
Label::Label(iVector2 pos, iVector2 size, const char *text, GUIElement &parent, StyleSheet &style) : GUIElement(pos, size, &parent, &style), _text(text)
{
  container = false;
  _selectable = false;
}


Label::Label(const Label &from) : GUIElement(from)
{
  _text = from._text;
}

//================= DESTRUCTOR ===================//
Label::~Label()
{
  _text.clear();
}

//================= PUBLIC ===================//
void Label::render()
{
  if (GUIManager::canRender() != true || _visible == false)
    return;
  
  renderLabel();
}

//================= PROTECTED ===================//
void Label::renderLabel()
{
  Style *style = _styles->getStyle(_state);

  if (!style || !style->font)
    return;

  iVector2 renderPos(0, 0);
  iVector2 globalPos = getGlobalPosition();

  switch (style->horizontalAlignment)
  {
  case Left:
  case Top:
    renderPos.x = 0;
    break;
  case Center:
    renderPos.x = (_size.x - (_text.length() * style->font->width)) / 2;
    break;
  case Right:
  case Bottom:
    renderPos.x = _size.x - (_text.length() * style->font->width);
    break;
  }

  switch (style->verticalAlignment)
  {
  case Top:
  case Left:
    renderPos.y = 0;
    break;
  case Center:
    renderPos.y = (_size.y - style->font->height) / 2;
    break;
  case Bottom:
  case Right:
    renderPos.y = _size.y - style->font->height;
    break;
  }
  
  for (uint16_t i = 0; i < _text.length(); i++)
  {
    if (renderPos.x + style->font->width > _size.x || renderPos.y + style->font->height > _size.y)
      break;

    GUIManager::renderChar(globalPos + renderPos, _text[i], style->foregroundColor, style->font);
    renderPos.x += style->font->width;
  }
}
