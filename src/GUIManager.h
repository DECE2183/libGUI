#pragma once
// #include <ESP32Lib.h>
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
}