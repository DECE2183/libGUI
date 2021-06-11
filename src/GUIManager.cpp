#include "GUIManager.h"

namespace GUIManager
{
    Screen *_screen;
    GUIElement * _background;

    iVector2 _screenSize;

    void setScreen(Screen * scr)
    {
        if (_screen != NULL)
            delete _screen;

        _screen = scr;
    }

    void setBackground(GUIElement * background)
    {
        if (_background != NULL)
            delete _background;

        _background = background;
    }

    Screen * getScreen()
    {
        return _screen;
    }

    void render()
    {
        if (_background == NULL)
            return;

        _background->render();
    }
}