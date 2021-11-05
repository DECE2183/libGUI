#include "GUIManager.hpp"

namespace GUIManager
{
  bool _canRender;

  GDisplay *_display;
  GUIElement *_background;

  GUIElement *_selectionBase;
  GUIElement *_selectedElement;

  iVector2 _displaySize;
}

void GUIManager::setDisplay(GDisplay *display)
{
  _display = display;
  render();
}
void GUIManager::setDisplay(GDisplay &display)
{
  setDisplay(&display);
}

void GUIManager::setBackground(GUIElement *background)
{
  _background = background;
  render();
}
void GUIManager::setBackground(GUIElement &background)
{
  setBackground(&background);
}

GDisplay *GUIManager::getDisplay()
{
  return _display;
}

void GUIManager::render()
{
  if (_background == NULL || _display == NULL)
    return;

  _canRender = true;

  _display->fill(GColor());
  _background->render();
}

bool GUIManager::canRender()
{
  return _canRender;
}

void GUIManager::renderChar(iVector2 pos, char ch, GColor color, const GFont *font)
{
  if (canRender() == false) return;
  if (!font) return;
  if (font->isCharValid(ch) == false) return;

  _display->drawChar(pos, ch, color, font);
}
void GUIManager::renderChar(iVector2 pos, char ch, GColor color, const GFont &font)
{
  renderChar(pos, ch, color, &font);
}