#pragma once
#include <ESP32Lib.h>

#include "Elements/GUIElement.h"

namespace GUIManager
{
    typedef Graphics<unsigned char> Screen;

    void setScreen(Screen *scr);
    void setBackground(GUIElement * background);
    Screen *getScreen();

    void render();
}