#pragma once
#include "Section.h"
#include "Label.h"

class Window : public Section
{
public:
  //------ Constructors ------//
  Window();
  Window(iVector2 pos, iVector2 size, const char *header);
  Window(iVector2 pos, iVector2 size, GUIElement *parent, const char *header);
  Window(iVector2 pos, iVector2 size, GUIElement &parent, const char *header);

  Window(iVector2 pos, iVector2 size, StyleSheet *style, const char *header);
  Window(iVector2 pos, iVector2 size, StyleSheet &style, const char *header);
  Window(iVector2 pos, iVector2 size, GUIElement *parent, StyleSheet *style, const char *header);
  Window(iVector2 pos, iVector2 size, GUIElement &parent, StyleSheet &style, const char *header);

  Window(iVector2 pos, iVector2 size, StyleSheet *style, StyleSheet *headerStyle, const char *header);
  Window(iVector2 pos, iVector2 size, StyleSheet &style, StyleSheet &headerStyle, const char *header);
  Window(iVector2 pos, iVector2 size, GUIElement *parent, StyleSheet *style, StyleSheet *headerStyle, const char *header);
  Window(iVector2 pos, iVector2 size, GUIElement &parent, StyleSheet &style, StyleSheet &headerStyle, const char *header);

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