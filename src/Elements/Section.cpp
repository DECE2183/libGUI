#include "Section.h"

Section::Section(iVector2 pos, iVector2 size) : GUIElement(pos, size)
{
}

Section::Section(iVector2 pos, iVector2 size, GUIElement *parent) : GUIElement(pos, size, parent)
{
}

void Section::render()
{
    iVector2 globalPos = getGlobalPosition();

    // Draw background
    GUIManager::getScreen()->fillRect(globalPos.x, globalPos.y, _size.x, _size.y, _backgroundColor);

    // Draw borders
    if (_borderThickness[0] > 0)
        GUIManager::getScreen()->yLine(globalPos.y, globalPos.y + _size.y, globalPos.x, _borderColor);
    if (_borderThickness[1] > 0)
        GUIManager::getScreen()->xLine(globalPos.x, globalPos.x + _size.x, globalPos.y, _borderColor);
    if (_borderThickness[2] > 0)
        GUIManager::getScreen()->yLine(globalPos.y, globalPos.y + _size.y, globalPos.x + _size.x, _borderColor);
    if (_borderThickness[3] > 0)
        GUIManager::getScreen()->xLine(globalPos.x, globalPos.x + _size.x, globalPos.y + _size.x, _borderColor);

    renderChildren();
}