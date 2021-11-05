#pragma once

#include <string>
#include <sstream>
#include <GUIManager.hpp>
#include "GUIElement.hpp"

using namespace std;

class Label : public GUIElement
{
public:
  //------ Constructors ------//
  Label(iVector2 pos, iVector2 size, const char *text, GUIElement *parent, StyleSheet *style);
  Label(iVector2 pos, iVector2 size, const char *text, GUIElement &parent, StyleSheet &style = DefaultStyle);

  Label(const Label &from);

  //------ Destructor ------//
  virtual ~Label();

  //------ Getters ------//
  const string &getText() const { return _text; }
  const char *getPureText() const { return _text.c_str(); }

  //------ Setters ------//
  void setText(const char *text)
  {
    _text = text;
    if (autorender == true)
      render();
  }
  void setText(const string &text)
  {
    _text = text;
    if (autorender == true)
      render();
  }

  //------ Control methods ------//
  template <typename T>
  static string toString(T val)
  {
    static stringstream stream;

    stream.str("");
    stream.clear();
    stream << val;

    return stream.str();
  }

  //------ Virtual methods ------//
  virtual void render();

protected:
  string _text;

  void renderLabel();
};