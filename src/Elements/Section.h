#pragma once
#include "GUIElement.h"
#include <GUIManager.h>
#include "../Utils/Style.h"

class Section : public GUIElement
{
public:
  //------ Constructors ------//
  Section() : GUIElement() {};
  Section(GUIElement &parent) : GUIElement(parent) {};
  Section(Style &normalStyle) : GUIElement() { setStyle(&normalStyle); };
  Section(GUIElement &parent, Style &normalStyle) : GUIElement(parent) { setStyle(&normalStyle); };

  Section(iVector2 pos, iVector2 size);
  Section(iVector2 pos, iVector2 size, GUIElement &parent);
  Section(iVector2 pos, iVector2 size, Style &normalStyle);
  Section(iVector2 pos, iVector2 size, GUIElement &parent, Style &normalStyle);

  //------ Getters ------//
  Style *getStyle() { return _normalStateStyle; }

  //------ Setters ------//
  void setStyle(Style *normalStyle) { _normalStateStyle = normalStyle; }
  void setStyle(Style &normalStyle) { setStyle(&normalStyle); }

  //------ Control methods ------//

  //------ Virtual methods ------//
  virtual void render();

protected:
  Style *_normalStateStyle;
  
  virtual void renderBackground();
  virtual void renderBorders();
};