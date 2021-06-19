#pragma once
#include <GUIManager.h>
#include <string>
#include "GUIElement.h"

class Label : public GUIElement
{
public:
  //------ Constructors ------//
  Label();

  Label(iVector2 pos, iVector2 size, const char *text);
  Label(iVector2 pos, iVector2 size, GUIElement *parent, const char *text);
  Label(iVector2 pos, iVector2 size, GUIElement &parent, const char *text);

  Label(iVector2 pos, iVector2 size, StyleSheet *style, const char *text);
  Label(iVector2 pos, iVector2 size, StyleSheet &style, const char *text);
  Label(iVector2 pos, iVector2 size, GUIElement *parent, StyleSheet *style, const char *text);
  Label(iVector2 pos, iVector2 size, GUIElement &parent, StyleSheet &style, const char *text);

  Label(const Label &from);

  //------ Destructor ------//
  virtual ~Label();

  //------ Getters ------//
  const std::string &getText() const { return _text; }
  const char *getPureText() const { return _text.c_str(); }

  //------ Setters ------//
  void setText(const char *text)
  {
    _text = text;
    if (autorender == true)
      render();
  }

  //------ Control methods ------//

  //------ Virtual methods ------//
  virtual void render();

protected:
  std::string _text;

  void renderLabel();
};