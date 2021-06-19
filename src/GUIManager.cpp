#include "GUIManager.h"

namespace GUIManager
{
  bool _canRender;

  Screen *_screen;
  GUIElement *_background;

  GUIElement *_selectionBase;
  GUIElement *_selectedElement;

  iVector2 _screenSize;
}

void GUIManager::setScreen(GUIManager::Screen *scr)
{
  if (_screen != NULL)
    delete _screen;

  _screen = scr;
}
void GUIManager::setScreen(GUIManager::Screen &scr)
{
  setScreen(&scr);
}

void GUIManager::setBackground(GUIElement *background)
{
  if (_background != NULL)
    delete _background;

  _background = background;
}
void GUIManager::setBackground(GUIElement &background)
{
  setBackground(&background);
}

GUIManager::Screen *GUIManager::getScreen()
{
  return _screen;
}

void GUIManager::render()
{
  if (_background == NULL || _screen == NULL)
    return;

  _canRender = true;

  _screen->clear(0x00);
  _background->render();
}

bool GUIManager::canRender()
{
  return _canRender;
}

void GUIManager::renderChar(iVector2 pos, char ch, Color color, const GFont *font)
{
  if (canRender() == false) return;
  if (!font) return;
  if (font->isCharValid(ch) == false) return;

  unsigned int chH = font->getHeight();
  unsigned int bRow = font->getBytesPerRow();

  const unsigned char *chPix = font->getPixels() + (ch - font->getFirstChar()) * (chH * bRow);

  for (unsigned int row = 0; row < chH; row++)
  {
    for (unsigned char x = 0; x < 8; x++)
    {
      for (unsigned char b = 0; b < bRow; b++)
      {
        if (chPix[row * bRow + b] & (0b10000000U >> x))
          _screen->dotFast(pos.x + x + b*8, pos.y + row, color);
      }
    }
  }
}
void GUIManager::renderChar(iVector2 pos, char ch, Color color, const GFont &font)
{
  renderChar(pos, ch, color, &font);
}