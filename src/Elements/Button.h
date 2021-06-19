#pragma once
#include "Section.h"
#include "Label.h"

class Button : public Section
{
public:
  //------ Constructors ------//
  Button();
  Button(iVector2 pos, iVector2 size, const char *text);
  Button(iVector2 pos, iVector2 size, GUIElement *parent, const char *text);
  Button(iVector2 pos, iVector2 size, GUIElement &parent, const char *text);

  Button(iVector2 pos, iVector2 size, StyleSheet *style, const char *text);
  Button(iVector2 pos, iVector2 size, StyleSheet &style, const char *text);
  Button(iVector2 pos, iVector2 size, GUIElement *parent, StyleSheet *style, const char *text);
  Button(iVector2 pos, iVector2 size, GUIElement &parent, StyleSheet &style, const char *text);

  Button(const Button &from);

  //------ Getters ------//
  const Label &getLabel() const { return _label; }

  //------ Setters ------//
  //------ Control methods ------//

  //------ Virtual methods ------//
  virtual void render();
  virtual void setState(State state);

protected:
  Label _label;
  
  void setUpLabel();

  virtual void renderLabel();
};