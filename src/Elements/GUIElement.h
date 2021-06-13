#pragma once
#include <stdlib.h>
#include <vector>
#include "../Utils/Vector.h"

class GUIElement
{
public:
  //------ Constructors ------//
  GUIElement(){};
  GUIElement(GUIElement *parent);
  GUIElement(iVector2 pos, iVector2 size);
  GUIElement(iVector2 pos, iVector2 size, GUIElement * parent);

  //------ Destructor ------//
  virtual ~GUIElement();

  //------ Operators ------//
  bool equal(GUIElement *el)
  {
    return this == el;
  }
  bool operator==(GUIElement *el) const
  {
    return this == el;
  }

  //------ Getters ------//
  bool getVisible()                          { return _visible; }
  const iVector2 &getPosition()              { return _position; }
  const iVector2 &getSize()                  { return _size; }
  GUIElement * getParent()                   { return _parent; }
  GUIElement * getChild(uint16_t childIndex) { return _children.at(childIndex); }
  uint16_t childrenCount()                   { return _children.size(); }

  //------ Setters ------//
  void setVisible(bool vis)
  {
    _visible = vis;
    renderParent();
  }
  void setPosition(const iVector2 &pos)
  {
    _position = pos;
    renderParent();
  }
  void setSize(const iVector2 &size)
  {
    _size = size;
    renderParent();
  }
  void setPosition(int x, int y)
  {
    setPosition(iVector2(x, y));
  }
  void setSize(int x, int y)
  {
    setSize(iVector2(x, y));
  }


  //------ Control methods ------//
  void addChild(GUIElement *child);
  void addChild(GUIElement &child)         { addChild(&child); }
  void removeChild(uint16_t childIndex);
  void removeChild(GUIElement *child);
  void removeChild(GUIElement &child)      { removeChild(&child); }
  bool hasChild(GUIElement *child);
  bool hasChild(GUIElement &child)         { return hasChild(&child); }
  bool hasChildren();
  void setParent(GUIElement *parent);
  void setParent(GUIElement &parent)       { setParent(&parent); }
  bool hasParent();

  void bringToFront();
  void bringToFront(GUIElement *child);
  void bringToFront(GUIElement &child)     { bringToFront(&child); }
  void bringToFront(uint16_t childIndex);

  void toBackground();
  void toBackground(GUIElement *child);
  void toBackground(GUIElement &child)     { toBackground(&child); }
  void toBackground(uint16_t childIndex);

  iVector2 getGlobalPosition();
  iVector2 getParentSize();

  //------ Virtual methods ------//
  virtual void render();

protected:
  int findChildIndex(GUIElement * child);
  void renderParent();
  void renderChildren();

  bool _visible = true;
  iVector2 _position = iVector2(0, 0);
  iVector2 _size = iVector2(0, 0);

  GUIElement * _parent;
  std::vector<GUIElement*> _children;
};