#pragma once
#include "Section.h"
#include "Label.h"

class Button : public Section
{
public:
  //------ Constructors ------//
  Button(iVector2 pos, iVector2 size, const char *text, GUIElement *parent, StyleSheet *style);
  Button(iVector2 pos, iVector2 size, const char *text, GUIElement &parent, StyleSheet &style = DefaultButtonStyle);

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
};