#include "Section.h"

//================= CONSTRUCTOR ===================//
Section::Section() : GUIElement() {}
Section::Section(iVector2 pos, iVector2 size) : GUIElement(pos, size) {}
Section::Section(iVector2 pos, iVector2 size, GUIElement *parent) : GUIElement(pos, size, parent) {}
Section::Section(iVector2 pos, iVector2 size, GUIElement &parent) : GUIElement(pos, size, &parent) {}

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
  GUIManager::Screen * screen = GUIManager::getScreen();
  iVector2 globalPos = getGlobalPosition();

  Style *style = _styles->getStyle(_state);
  uint8_t *bThickness = style->borderThickness;

  screen->fillRect(globalPos.x + bThickness[0], globalPos.y + bThickness[1], _size.x - bThickness[0] - bThickness[2], _size.y - bThickness[1] - bThickness[3], style->backgroundColor);
}

void Section::renderBorders()
{
  GUIManager::Screen * screen = GUIManager::getScreen();
  iVector2 globalPos = getGlobalPosition();
  Style *style = _styles->getStyle(_state);

  // Left border
  if (style->borderThickness[0] > 0)
  {
    for (uint8_t i = 0; i < style->borderThickness[0]; i++)
      screen->yLine(globalPos.y, globalPos.y + _size.y, globalPos.x + i, style->borderColor);
  }

  // Top border
  if (style->borderThickness[1] > 0)
  {
    for (uint8_t i = 0; i < style->borderThickness[1]; i++)
      screen->xLine(globalPos.x + style->borderThickness[0], globalPos.x + _size.x - style->borderThickness[2], globalPos.y + i, style->borderColor);
  }

  // Right border
  if (style->borderThickness[2] > 0)
  {
    for (uint8_t i = 0; i < style->borderThickness[2]; i++)
      screen->yLine(globalPos.y, globalPos.y + _size.y, globalPos.x + _size.x - i - 1, style->borderColor);
  }

  // Bottom border
  if (style->borderThickness[3] > 0)
  {
    for (uint8_t i = 0; i < style->borderThickness[3]; i++)
      screen->xLine(globalPos.x + style->borderThickness[0], globalPos.x + _size.x - style->borderThickness[2], globalPos.y + _size.y - i - 1, style->borderColor);
  }
}