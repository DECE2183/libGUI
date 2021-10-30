#pragma once
#include <GUIManager.h>
#include <string>
#include "GUIElement.h"

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
  const String &getText() const { return _text; }
  const char *getPureText() const { return _text.c_str(); }

  //------ Setters ------//
  void setText(const char *text)
  {
    _text = text;
    if (autorender == true)
      render();
  }
  void setText(const String &text)
  {
    _text = text;
    if (autorender == true)
      render();
  }

  //------ Control methods ------//

  //------ Virtual methods ------//
  virtual void render();

protected:
  String _text;

  void renderLabel();
};