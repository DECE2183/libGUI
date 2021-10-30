#include "Window.h"

#define BASE_OFFSET 5
#define BASE_HEIGHT 24

//================= CONSTRUCTOR ===================//

// Window::Window(iVector2 pos, iVector2 size, StyleSheet *style, const char *header) : Section(pos, size, style),
//     _headerSection(iVector2(0, 0), iVector2(size.x, BASE_HEIGHT), DefaultWindowHeaderStyle),
//     _headerLabel(iVector2(BASE_OFFSET, 0), iVector2(size.x, BASE_HEIGHT), _headerSection, header)
// {}
// Window::Window(iVector2 pos, iVector2 size, StyleSheet &style, const char *header) : Section(pos, size, &style),
//     _headerSection(iVector2(0, 0), iVector2(size.x, BASE_HEIGHT), DefaultWindowHeaderStyle),
//     _headerLabel(iVector2(BASE_OFFSET, 0), iVector2(size.x, BASE_HEIGHT), _headerSection, header)
// {}
// Window::Window(iVector2 pos, iVector2 size, GUIElement *parent, StyleSheet *style, const char *header) : Section(pos, size, parent, style),
//     _headerSection(iVector2(0, 0), iVector2(size.x, BASE_HEIGHT), DefaultWindowHeaderStyle),
//     _headerLabel(iVector2(BASE_OFFSET, 0), iVector2(size.x, BASE_HEIGHT), _headerSection, header)
// {}
// Window::Window(iVector2 pos, iVector2 size, GUIElement &parent, StyleSheet &style, const char *header) : Section(pos, size, &parent, &style),
//     _headerSection(iVector2(0, 0), iVector2(size.x, BASE_HEIGHT), DefaultWindowHeaderStyle),
//     _headerLabel(iVector2(BASE_OFFSET, 0), iVector2(size.x, BASE_HEIGHT), _headerSection, header)
// {}

Window::Window(iVector2 pos, iVector2 size, const char *header, StyleSheet *style, StyleSheet *headerStyle) :
    Section(pos, size, style),
    _headerSection(iVector2(0, 0), iVector2(size.x, BASE_HEIGHT), headerStyle),
    _headerLabel(iVector2(BASE_OFFSET, 0), iVector2(size.x, BASE_HEIGHT), header, &_headerSection, headerStyle)
{}
Window::Window(iVector2 pos, iVector2 size, const char *header, StyleSheet &style, StyleSheet &headerStyle) :
    Window(pos, size, header, &style, &headerStyle)
{}
Window::Window(iVector2 pos, iVector2 size, const char *header, GUIElement *parent, StyleSheet *style, StyleSheet *headerStyle) :
    Section(pos, size, parent, style),
    _headerSection(iVector2(0, 0), iVector2(size.x, BASE_HEIGHT), headerStyle),
    _headerLabel(iVector2(BASE_OFFSET, 0), iVector2(size.x, BASE_HEIGHT), header, &_headerSection, headerStyle)
{}
Window::Window(iVector2 pos, iVector2 size, const char *header, GUIElement &parent, StyleSheet &style, StyleSheet &headerStyle) :
    Window(pos, size, header, &parent, &style, &headerStyle)
{}

Window::Window(const Window &from) : Section(from),
    _headerSection(from._headerSection.getPosition(), from._headerSection.getSize(), from._headerSection.getStyle()),
    _headerLabel(from._headerLabel.getPosition(), from._headerLabel.getSize(), from._headerLabel.getPureText(), &_headerSection, from._headerLabel.getStyle())
{}

//================= PUBLIC ===================//
void Window::render()
{
  if (GUIManager::canRender() != true || _visible == false)
    return;

  renderBackground();
  renderChildren();
  renderBorders();
  renderHeader();
}

void Window::setState(State state)
{
  _state = state;
  _headerSection.setState(state);
  
  if (autorender == true)
    render();
}

//================= PROTECTED ===================//
void Window::renderHeader()
{
  iVector2 globalPos = getGlobalPosition();
  globalPos.y -= _headerSection.getSize().y;
  _headerSection.setPosition(globalPos);
}