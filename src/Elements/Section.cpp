#include "Section.h"

//================= CONSTRUCTOR ===================//
Section::Section(iVector2 pos, iVector2 size) : GUIElement(pos, size) {}
Section::Section(iVector2 pos, iVector2 size, GUIElement &parent) : GUIElement(pos, size, &parent) {}
Section::Section(iVector2 pos, iVector2 size, Style &normalStyle) : GUIElement(pos, size) { setStyle(&normalStyle); }
Section::Section(iVector2 pos, iVector2 size, GUIElement &parent, Style &normalStyle) : GUIElement(pos, size, &parent) { setStyle(&normalStyle); }

//================= PUBLIC ===================//
void Section::render()
{
  renderBackground();
  renderChildren();
  renderBorders();
}


//================= PROTECTED ===================//
void Section::renderBackground()
{
  GUIManager::Screen * screen = GUIManager::getScreen();
  iVector2 globalPos = getGlobalPosition();

  uint8_t *bThickness = _normalStateStyle->borderThickness;

  screen->fillRect(globalPos.x + bThickness[0], globalPos.y + bThickness[1], _size.x - bThickness[0] - bThickness[2], _size.y - bThickness[1] - bThickness[3], _normalStateStyle->backgroundColor);
}

void Section::renderBorders()
{
  GUIManager::Screen * screen = GUIManager::getScreen();
  iVector2 globalPos = getGlobalPosition();

  // Left border
  if (_normalStateStyle->borderThickness[0] > 0)
  {
    for (uint8_t i = 0; i < _normalStateStyle->borderThickness[0]; i++)
      screen->yLine(globalPos.y, globalPos.y + _size.y, globalPos.x + i, _normalStateStyle->borderColor);
  }

  // Top border
  if (_normalStateStyle->borderThickness[1] > 0)
  {
    for (uint8_t i = 0; i < _normalStateStyle->borderThickness[1]; i++)
      screen->xLine(globalPos.x + _normalStateStyle->borderThickness[0], globalPos.x + _size.x - _normalStateStyle->borderThickness[2], globalPos.y + i, _normalStateStyle->borderColor);
  }

  // Right border
  if (_normalStateStyle->borderThickness[2] > 0)
  {
    for (uint8_t i = 0; i < _normalStateStyle->borderThickness[2]; i++)
      screen->yLine(globalPos.y, globalPos.y + _size.y, globalPos.x + _size.x - i - 1, _normalStateStyle->borderColor);
  }

  // Bottom border
  if (_normalStateStyle->borderThickness[3] > 0)
  {
    for (uint8_t i = 0; i < _normalStateStyle->borderThickness[3]; i++)
      screen->xLine(globalPos.x + _normalStateStyle->borderThickness[0], globalPos.x + _size.x - _normalStateStyle->borderThickness[2], globalPos.y + _size.y - i - 1, _normalStateStyle->borderColor);
  }
}