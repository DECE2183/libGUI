#pragma once
#include "Style.h"

struct StyleSheet
{
  StyleSheet(Style *style)
  {
    styles[Normal] = style;
    styles[Hover] = style;
    styles[Pressed] = style;
  }
  StyleSheet(Style &style) : StyleSheet(&style){};

  StyleSheet(Style *n_style, Style *h_style, Style *p_style)
  {
    styles[Normal] = n_style;
    styles[Hover] = h_style;
    styles[Pressed] = p_style;
  }
  StyleSheet(Style &n_style, Style &h_style, Style &p_style) : StyleSheet(&n_style, &h_style, &p_style){};

  Style *getStyle(State state) const { return styles[state]; }

  void setStyle(State state, Style *style) { styles[state] = style; }
  void setStyle(State state, Style &style) { styles[state] = &style; }

  Style *operator[](State state)
  {
    return styles[state];
  }

  Style *styles[State::EnumSize];
};