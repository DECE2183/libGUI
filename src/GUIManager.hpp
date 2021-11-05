#pragma once

#include <Elements/GUIElement.hpp>
#include "Utils/GDisplay.hpp"

namespace GUIManager
{
  // Specify the display you want to work with
  void setDisplay(GDisplay *display);
  // Specify the display you want to work with
  void setDisplay(GDisplay &display);
  // Get current slected display
  GDisplay *getDisplay();

  // Specify the root element which becomes the background element
  void setBackground(GUIElement *background);
  // Specify the root element which becomes the background element
  void setBackground(GUIElement &background);

  void render();
  bool canRender();

  void renderChar(iVector2 pos, char ch, GColor color, const GFont *Font);
  void renderChar(iVector2 pos, char ch, GColor color, const GFont &font);
}