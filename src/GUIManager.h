#pragma once
#include <Tools/Log.h>
#include <Graphics/Graphics.h>
#include <Elements/GUIElement.h>

namespace GUIManager
{
  typedef Graphics<unsigned char> Screen;

  void setScreen(Screen *scr);
  void setBackground(GUIElement *background);
  void setScreen(Screen &scr);
  void setBackground(GUIElement &background);
  Screen *getScreen();

  void render();
  bool canRender();

  void renderChar(iVector2 pos, char ch, Color color, const GFont *Font);
  void renderChar(iVector2 pos, char ch, Color color, const GFont &font);
}