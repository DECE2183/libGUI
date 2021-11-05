#include "Section.hpp"

//================= CONSTRUCTOR ===================//
Section::Section(iVector2 pos, iVector2 size, StyleSheet *style) : GUIElement(pos, size, style) {}
Section::Section(iVector2 pos, iVector2 size, StyleSheet &style) : GUIElement(pos, size, &style) {}
Section::Section(iVector2 pos, iVector2 size, GUIElement *parent, StyleSheet *style) : GUIElement(pos, size, parent, style) {}
Section::Section(iVector2 pos, iVector2 size, GUIElement &parent, StyleSheet &style) : GUIElement(pos, size, &parent, &style) {}

Section::Section(const Section &from) : GUIElement(from) {}

//================= PUBLIC ===================//
void Section::render()
{
  if (GUIManager::canRender() != true || _visible == false)
    return;

  renderBackground();
  renderChildren();
  renderBorders();
}


//================= PROTECTED ===================//
void Section::renderBackground()
{
  GDisplay *display = GUIManager::getDisplay();
  iVector2 globalPos = getGlobalPosition();

  Style *style = _styles->getStyle(_state);
  uint8_t *bThickness = style->borderThickness;

  display->drawRect(globalPos.x + bThickness[0], globalPos.y + bThickness[1], _size.x - bThickness[0] - bThickness[2], _size.y - bThickness[1] - bThickness[3], style->backgroundColor);
}

void Section::renderBorders()
{
  GDisplay * display = GUIManager::getDisplay();
  iVector2 globalPos = getGlobalPosition();
  Style *style = _styles->getStyle(_state);

  // Left border
  if (style->borderThickness[0] > 0)
  {
    for (uint8_t i = 0; i < style->borderThickness[0]; i++)
      display->drawVLine(globalPos.x + i, globalPos.y, _size.y, style->borderColor);
  }

  // Top border
  if (style->borderThickness[1] > 0)
  {
    for (uint8_t i = 0; i < style->borderThickness[1]; i++)
      display->drawHLine(globalPos.x + style->borderThickness[0], globalPos.y + i, _size.x - style->borderThickness[2], style->borderColor);
  }

  // Right border
  if (style->borderThickness[2] > 0)
  {
    for (uint8_t i = 0; i < style->borderThickness[2]; i++)
      display->drawVLine(globalPos.x + _size.x - i - 1, globalPos.y, _size.y, style->borderColor);
  }

  // Bottom border
  if (style->borderThickness[3] > 0)
  {
    for (uint8_t i = 0; i < style->borderThickness[3]; i++)
      display->drawHLine(globalPos.x + style->borderThickness[0], globalPos.y + _size.y - i - 1, _size.x - style->borderThickness[2], style->borderColor);
  }
}