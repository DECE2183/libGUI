#pragma once

#include <stdlib.h>
#include <vector>
#include "../Utils/Vector.hpp"
#include "../Utils/Event.hpp"
#include "../Styles/DefaultStyle.hpp"

class GUIElement
{
public:
  //------ Constructors ------//
  GUIElement(StyleSheet *style);
  GUIElement(GUIElement *parent, StyleSheet *style);
  GUIElement(iVector2 pos, iVector2 size, StyleSheet *style);
  GUIElement(iVector2 pos, iVector2 size, GUIElement *parent, StyleSheet *style);

  //------ Destructor ------//
  virtual ~GUIElement();

  //------ Copy constructor ------//
  GUIElement(const GUIElement &from);


  //------ Variables ------//
  bool container = true;
  bool autorender = true;

  Event<GUIElement> onClick = Event<GUIElement>(this);
  Event<GUIElement> onSelect = Event<GUIElement>(this);


  //------ Operators ------//
  bool equal(GUIElement *el)
  {
    return this == el;
  }

  //------ Getters ------//
  bool isSelecable() const                         { return _selectable; }
  bool isVisible() const                           { return _visible; }
  bool isSelected() const                          { return (_state != Normal); }
  const iVector2 &getPosition() const              { return _position; }
  const iVector2 &getSize() const                  { return _size; }
  GUIElement *getParent() const                    { return _parent; }
  GUIElement *getChild(uint16_t childIndex) const  { return _children.at(childIndex); }
  uint16_t childrenCount() const                   { return _children.size(); }
  State getState() const                           { return _state; }
  StyleSheet *getStyle() const                     { return _styles; }
  Style *getStyle(State state) const               { return _styles->getStyle(state); }

  //------ Setters ------//
  void setSelectable(bool sel)
  {
    _selectable = sel;
  }
  void setVisible(bool vis)
  {
    _visible = vis;
    if (autorender == true)
    {
      if (vis == true)
        render();
      else
        renderParent();
    }
  }
  virtual void setPosition(int x, int y)
  {
    setPosition(iVector2(x, y));
  }
  void setSize(int x, int y)
  {
    setSize(iVector2(x, y));
  }
  void setStyle(StyleSheet *style)
  {
    _styles = style;
    if (autorender == true)
      render();
  }
  void setStyle(StyleSheet &style)
  {
    setStyle(&style);
  }
  void setStyle(State state, Style *style)
  {
    _styles->setStyle(state, style);
    if (autorender == true)
      render();
  }
  void setStyle(State state, Style &style)
  {
    setStyle(state, &style);
  }

  //------ Control methods ------//
  void addChild(GUIElement *child);
  void addChild(GUIElement &child)         { addChild(&child); }
  void removeChild(uint16_t childIndex);
  void removeChild(GUIElement *child);
  void removeChild(GUIElement &child)      { removeChild(&child); }
  bool hasChild(const GUIElement *child) const;
  bool hasChild(GUIElement &child) const   { return hasChild(&child); }
  bool hasChildren() const;
  void setParent(GUIElement *parent);
  void setParent(GUIElement &parent)       { setParent(&parent); }
  bool hasParent() const;

  void bringToFront();
  void bringToFront(GUIElement *child);
  void bringToFront(GUIElement &child)     { bringToFront(&child); }
  void bringToFront(uint16_t childIndex);

  void toBackground();
  void toBackground(GUIElement *child);
  void toBackground(GUIElement &child)     { toBackground(&child); }
  void toBackground(uint16_t childIndex);

  iVector2 getGlobalPosition() const;
  iVector2 getParentSize() const;

  int findChildIndex(const GUIElement *child) const;

  //------ Virtual methods ------//
  virtual void setState(State state);
  virtual void render();
  virtual void select();
  virtual void deselect();
  virtual void startClick();
  virtual void endClick();
  virtual void setPosition(const iVector2 &pos);
  virtual void setSize(const iVector2 &size);

  virtual GUIElement *getNext(uint16_t selectIndex);
  virtual GUIElement *getPrev(uint16_t selectIndex);

protected:
  void renderParent();
  void renderChildren();

  bool _selectable = true;
  bool _visible = true;
  iVector2 _position = iVector2(0, 0);
  iVector2 _size = iVector2(0, 0);

  State _state = Normal;
  StyleSheet *_styles;

  GUIElement *_parent;
  std::vector<GUIElement*> _children;
};