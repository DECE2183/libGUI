#pragma once
#include "GUIElement.h"
#include <GUIManager.h>

class Section : public GUIElement
{
public:
  //------ Constructors ------//
  Section(iVector2 pos, iVector2 size, StyleSheet *style);
  Section(iVector2 pos, iVector2 size, StyleSheet &style = DefaultStyle);
  Section(iVector2 pos, iVector2 size, GUIElement *parent, StyleSheet *style);
  Section(iVector2 pos, iVector2 size, GUIElement &parent, StyleSheet &style = DefaultStyle);

  Section(const Section &from);

  //------ Getters ------//
  //------ Setters ------//
  //------ Control methods ------//

  //------ Virtual methods ------//
  virtual void render();

protected:
  virtual void renderBackground();
  virtual void renderBorders();
};