#pragma once
#include "Section.h"
#include "Button.h"
#include "Label.h"

#include <stdlib.h>
#include <string>

template <typename T>
class Range : Section
{
public:
  //------ Constructors ------//
  Range(iVector2 pos, iVector2 size, GUIElement *parent, StyleSheet *style, StyleSheet *btnStyle) : Section(pos, size, parent, style),
    _left_btn(iVector2(0), iVector2(26, size.y - 4), "A", this, btnStyle),
    _value_lb(iVector2(0), iVector2(0, size.y), "", this, style),
    _right_btn(iVector2(0), iVector2(26, size.y - 4), "B", this, btnStyle)
  {
    _value_lb.setSelectable(true);
    alignControls();
    renderControls();
    setValue(defaultValue);

    // _value_lb.onClick.redirect<GUIElement>(onClick);
  }
  Range(iVector2 pos, iVector2 size, GUIElement &parent, StyleSheet &style = DefaultRangeStyle, StyleSheet &btnStyle = DefaultBorderlessIconButtonStyle) : Range(pos, size, &parent, &style, &btnStyle) {}

  Range(iVector2 pos, iVector2 size, T inc, GUIElement *parent, StyleSheet *style, StyleSheet *btnStyle) : Range(pos, size, parent, style, btnStyle)
  {
    increment = inc;
  }
  Range(iVector2 pos, iVector2 size, T inc, GUIElement &parent, StyleSheet &style = DefaultRangeStyle, StyleSheet &btnStyle = DefaultBorderlessIconButtonStyle) : Range(pos, size, parent, style, btnStyle)
  {
    increment = inc;
  }


  //------ Variables ------//
  const T defaultValue = 0;
  T minValue = 0;
  T maxValue = 255;
  T increment = 1;
  Event<Range> onClick = Event<Range>(this);
  Event<Range> onChange = Event<Range>(this);

  //------ Getters ------//
  T getValue() const { return _value; }

  //------ Setters ------//
  void setValue(T val)
  {
    if (val >= maxValue) val = maxValue;
    if (val <= minValue) val = minValue;

    _value = val;
    _value_lb.setText(String(val));
    if (autorender == true)
      render();
  }

  //------ Control methods ------//
  void encrease()
  {
    T newVal = _value + increment;
    _left_btn.select();

    if (newVal >= maxValue)
      setValue(maxValue);
    else
      setValue(newVal);

    onChange.trigger();
    _left_btn.deselect();
  }
  void decrease()
  {
    T newVal = _value - increment;
    _left_btn.select();

    if (newVal <= minValue)
      setValue(minValue);
    else
      setValue(newVal);

    onChange.trigger();
    _left_btn.deselect();
  }

  //------ Virtual methods ------//
  virtual void setSize(const iVector2 &size)
  {
    _size = size;
    alignControls();

    if (autorender == true)
      renderParent();
  }

  virtual GUIElement *getNext(uint16_t selectIndex)
  {
    encrease();
    return &_value_lb;
  }
  virtual GUIElement *getPrev(uint16_t selectIndex)
  {
    decrease();
    return &_value_lb;
  }

  virtual void render()
  {
    if (GUIManager::canRender() != true || _visible == false)
      return;

    renderBackground();
    renderControls();
    renderBorders();
  }

protected:
  T _value = defaultValue;

  Button _left_btn;
  Label _value_lb;
  Button _right_btn;

  void onBtnsClick(GUIElement &source)
  {
    onClick.trigger();
  }

  void renderControls()
  {
    _value_lb.render();
    _left_btn.render();
    _right_btn.render();
  }

  void alignControls()
  {
    _value_lb.autorender = false;
    _left_btn.autorender = false;
    _right_btn.autorender = false;

    _left_btn.setSize(_left_btn.getSize().x, _size.y - 4);
    _left_btn.setPosition(2, 2);

    _right_btn.setSize(_right_btn.getSize().x, _size.y - 4);
    _right_btn.setPosition(_size.x - _right_btn.getSize().x - 2, 2);

    _value_lb.setSize(_size.x - _left_btn.getSize().x - _right_btn.getSize().x, _size.y);
    _value_lb.setPosition(_left_btn.getSize().x, 0);

    _value_lb.autorender = true;
    _left_btn.autorender = true;
    _right_btn.autorender = true;
  }
};