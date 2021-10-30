#include "Range.h"
#include <stdlib.h>
#include <string>

//================= CONSTRUCTOR ===================//
// template <typename T>
// Range<T>::Range(iVector2 pos, iVector2 size, StyleSheet *style, StyleSheet *btnStyle) : Section(pos, size, style),
//   _value_lb(iVector2(0), size, "", style),
//   _left_btn(iVector2(0), iVector2(24, size.y), "A", btnStyle),
//   _right_btn(iVector2(size.x - 24, 0), iVector2(24, size.y), "B", btnStyle)
// {
//   container = false;
//   addChild(_value_lb);
//   addChild(_left_btn);
//   addChild(_right_btn);
// }
// template <typename T>
// Range<T>::Range(iVector2 pos, iVector2 size, StyleSheet &style, StyleSheet &btnStyle) : Range<T>(pos, size, &style, &btnStyle) {}

// template <typename T>
// Range<T>::Range(iVector2 pos, iVector2 size, GUIElement *parent, StyleSheet *style, StyleSheet *btnStyle) : Section(pos, size, parent, style),
//   _value_lb(iVector2(0), size, "", style),
//   _left_btn(iVector2(0), iVector2(24, size.y), "A", btnStyle),
//   _right_btn(iVector2(size.x - 24, 0), iVector2(24, size.y), "B", btnStyle)
// {
//   container = false;
//   addChild(_value_lb);
//   addChild(_left_btn);
//   addChild(_right_btn);
// }
// template <typename T>
// Range<T>::Range(iVector2 pos, iVector2 size, GUIElement &parent, StyleSheet &style, StyleSheet &btnStyle) : Range<T>(pos, size, &parent, &style, &btnStyle) {}

//================= PUBLIC ===================//
// template <typename T>
// T Range<T>::getValue() const
// {
//   return _value;
// }

// template <typename T>
// void Range<T>::setValue(T val)
// {
//   _value = val;
//   _value_lb.setText(String(val));
// }

// template <typename T>
// void Range<T>::encrease()
// {
//   _value += increment;
//   _value_lb.setText(String(_value));
// }

// template <typename T>
// void Range<T>::decrease()
// {
//   _value -= increment;
//   _value_lb.setText(String(_value));
// }

// template <typename T>
// void Range<T>::setPosition(const iVector2 &pos)
// {
//   _position = pos;
//   alignControls();

//   if (autorender == true)
//     renderParent();
// }

// template <typename T>
// void Range<T>::setSize(const iVector2 &size)
// {
//   _size = size;
//   alignControls();

//   if (autorender == true)
//     renderParent();
// }

//================= PROTECTED ===================//
// template <typename T>
// void Range<T>::alignControls()
// {
//   _value_lb.autorender = false;
//   _left_btn.autorender = false;
//   _right_btn.autorender = false;

//   _value_lb.setSize(_size);
//   _value_lb.setPosition(iVector2(0));

//   _left_btn.setSize(_left_btn.getSize().x, _size.y);
//   _left_btn.setPosition(iVector2(0));

//   _right_btn.setSize(_right_btn.getSize().x, _size.y);
//   _right_btn.setPosition(iVector2(_size.x - _right_btn.getSize().x, 0));

//   _value_lb.autorender = true;
//   _left_btn.autorender = true;
//   _right_btn.autorender = true;
// }