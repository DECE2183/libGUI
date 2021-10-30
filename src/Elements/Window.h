#pragma once
#include "Section.h"
#include "Label.h"

class Window : public Section
{
public:
  //------ Constructors ------//
  // Window(iVector2 pos, iVector2 size, const char *header, StyleSheet *style);
  // Window(iVector2 pos, iVector2 size, const char *header, StyleSheet &style = DefaultStyle);
  // Window(iVector2 pos, iVector2 size, const char *header, GUIElement *parent, StyleSheet *style);
  // Window(iVector2 pos, iVector2 size, const char *header, GUIElement &parent, StyleSheet &style = DefaultStyle);

  Window(iVector2 pos, iVector2 size, const char *header, StyleSheet *style, StyleSheet *headerStyle);
  Window(iVector2 pos, iVector2 size, const char *header, StyleSheet &style = DefaultStyle, StyleSheet &headerStyle = DefaultWindowHeaderStyle);
  Window(iVector2 pos, iVector2 size, const char *header, GUIElement *parent, StyleSheet *style, StyleSheet *headerStyle);
  Window(iVector2 pos, iVector2 size, const char *header, GUIElement &parent, StyleSheet &style = DefaultStyle, StyleSheet &headerStyle = DefaultWindowHeaderStyle);

  Window(const Window &from);

  //------ Getters ------//
  const Section &getHeaderSection() const { return _headerSection; }
  const Label &getHeaderLabel() const { return _headerLabel; }

  //------ Setters ------//
  //------ Control methods ------//

  //------ Virtual methods ------//
  virtual void render();
  virtual void setState(State state);

protected:
  Section _headerSection;
  Label _headerLabel;

  virtual void renderHeader();
};