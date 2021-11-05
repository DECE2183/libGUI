#include "GUIElement.hpp"
#include "../GUIManager.hpp"

//================= CONSTRUCTOR ===================//
GUIElement::GUIElement(StyleSheet *style)
{
  _styles = style;
}
GUIElement::GUIElement(GUIElement *parent, StyleSheet *style) : GUIElement(style)
{
  parent->addChild(this);
}
GUIElement::GUIElement(iVector2 pos, iVector2 size, StyleSheet *style) : GUIElement(style)
{
  _position = pos;
  _size = size;
}
GUIElement::GUIElement(iVector2 pos, iVector2 size, GUIElement *parent, StyleSheet *style) : GUIElement(pos, size, style)
{
  parent->addChild(this);
}

//================= DESTRUCTOR ===================//
GUIElement::~GUIElement()
{
  if (!_children.empty())
  {
    for (uint16_t i = 0; i < _children.size(); i++)
    {
      delete &_children.at(i);
    }
  }

  if (hasParent())
  {
    _parent->removeChild(this);
    _parent->render();
  }
}

//================= Copy constructor ===================//
GUIElement::GUIElement(const GUIElement &from)
{
  _visible = from._visible;

  _position = from._position;
  _size = from._size;

  _state = from._state;
  for (uint8_t i = 0; i < State::EnumSize; i++)
  {
    _styles[i] = from._styles[i];
  }

  _parent = from._parent;
  _children = from._children;

  container = from.container;
  autorender = from.autorender;
}

//================= PUBLIC ===================//
void GUIElement::addChild(GUIElement * child)
{
  if (!_children.empty())
  {
    for (uint16_t i = 0; i < _children.size(); i++)
    {
      if (_children.at(i) == child) return;
    }
  }

  if (child->hasParent() && child->getParent() != this)
  {
    child->getParent()->removeChild(child);
  }

  child->setParent(this);
  _children.push_back(child);
}

void GUIElement::removeChild(uint16_t childIndex)
{
  _children.erase(_children.begin() + childIndex);
}

void GUIElement::removeChild(GUIElement * child)
{
  int childIndex = findChildIndex(child);
  if (childIndex > -1)
  {
    removeChild(childIndex);
  }
}

bool GUIElement::hasChild(const GUIElement *child) const
{
  return (findChildIndex(child) > -1);
}

bool GUIElement::hasChildren() const
{
  return (!_children.empty());
}

void GUIElement::setParent(GUIElement *parent)
{
  _parent = parent;
}

bool GUIElement::hasParent() const
{
  return (_parent != NULL && _parent->hasChild(this));
}

iVector2 GUIElement::getGlobalPosition() const
{
  if (_parent == NULL)
    return _position;

  iVector2 pos = iVector2(0, 0);
  GUIElement * parent = _parent;
  while (parent != NULL)
  {
    pos += parent->getPosition();
    parent = parent->getParent();
  }
  pos += _position;

  return pos;
}

iVector2 GUIElement::getParentSize() const
{
  if (_parent == NULL)
    return _size;

  return _parent->getSize();
}

void GUIElement::render()
{
  if (GUIManager::canRender() != true || _visible == false)
    return;
}

void GUIElement::startClick()
{
  setState(Pressed);
}
void GUIElement::endClick()
{
  if (hasChildren() == true && container == true)
  {
    setState(Normal);
  }
  else
  {
    setState(Hover);
  }

  onClick.trigger();
}

void GUIElement::select()
{
  if (isSelecable() == false) return;

  setState(Hover);
  onSelect.trigger();
}
void GUIElement::deselect()
{
  setState(Normal);
}

void GUIElement::setState(State state)
{
  _state = state;
  if (autorender == true)
    render();

  if (!_children.empty())
  {
    for (uint16_t i = 0; i < _children.size(); i++)
    {
      _children.at(i)->setState(state);
    }
  }
}

void GUIElement::setPosition(const iVector2 &pos)
{
  _position = pos;
  if (autorender == true)
  {
    renderParent();
  }
}
void GUIElement::setSize(const iVector2 &size)
{
  _size = size;
  if (autorender == true)
  {
    renderParent();
  }
}

GUIElement *GUIElement::getNext(uint16_t selectIndex)
{
  GUIElement *child = _children.at(++selectIndex);

  while (selectIndex < childrenCount() - 1 && (child->isVisible() == false || child->isSelecable() == false))
  {
    child = _children.at(++selectIndex);
  }

  return child;
}

GUIElement *GUIElement::getPrev(uint16_t selectIndex)
{
  GUIElement *child = _children.at(--selectIndex);

  while (selectIndex > 0 && (child->isVisible() == false || child->isSelecable() == false))
  {
    child = _children.at(--selectIndex);
  }

  return child;
}

//================= PROTECTED ===================//
int GUIElement::findChildIndex(const GUIElement *child) const
{
  if (!_children.empty())
  {
    for (uint16_t i = 0; i < _children.size(); i++)
    {
      if (_children.at(i) == child)
        return i;
    }
  }

  return -1;
}

void GUIElement::renderParent()
{
  if (hasParent())
  {
    _parent->render();
  }
  else
  {
    render();
  }
}

void GUIElement::renderChildren()
{
  if (_children.empty()) return;

  for (uint16_t i = 0; i < _children.size(); i++)
  {
    _children.at(i)->render();
  }
}