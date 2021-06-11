#include "GUIElement.h"

//================= CONSTRUCTOR ===================//
GUIElement::GUIElement(iVector2 pos, iVector2 size)
{
  _position = pos;
  _size = size;
}

GUIElement::GUIElement(iVector2 pos, iVector2 size, GUIElement *parent)
{
  GUIElement(pos, size);
  _parent = parent;
}

//================= PUBLIC ===================//
void GUIElement::addChild(GUIElement * child)
{
  if (child->getParent() != this)
  {
    child->setParent(this);
  }

  if (!_children.empty())
  {
    for (uint16_t i = 0; i < _children.size(); i++)
    {
      if (_children.at(i) == child) return;
    }
  }

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

bool GUIElement::hasChild(GUIElement * child)
{
  return (findChildIndex(child) > -1);
}

bool GUIElement::hasChildren()
{
  return (!_children.empty());
}

void GUIElement::setParent(GUIElement *parent)
{
  _parent = parent;
}

bool GUIElement::hasParent()
{
  return (_parent != NULL && _parent->hasChild(this));
}

iVector2 GUIElement::getGlobalPosition()
{
  if (_parent == NULL)
    return _position;

  iVector2 pos = iVector2(0, 0);
  GUIElement * parent = _parent;
  while (parent != NULL)
  {
    pos += _parent->getPosition();
    parent = parent->getParent();
  }
  pos += _position;

  return pos;
}

iVector2 GUIElement::getParentSize()
{
  if (_parent == NULL)
    return _size;

  return _parent->getSize();
}


//================= PROTECTED ===================//
int GUIElement::findChildIndex(GUIElement * child)
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