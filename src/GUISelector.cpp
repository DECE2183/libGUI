#include "GUISelector.h"

Selector::Selector(GUIElement *base)
{
  _selectionBase = base;

  if (_selectionBase->hasChildren() == true)
  {
    _selectedElement = _selectionBase->getChild(0);
    _selectedElement->select();
  }
}
Selector::Selector(GUIElement &base) : Selector(&base) {}

void Selector::startClick()
{
  if (_selectedElement)
    _selectedElement->startClick();
}
void Selector::endClick()
{
  if (!_selectedElement) return;
  GUIElement *element = _selectedElement;

  element->endClick();

  if (element->container == true)
  {
    enter(element);
  }
}

void Selector::select(GUIElement *element)
{
  if (element->hasParent() == false || element->isSelecable() == false)
    return;

  if (_selectedElement)
    _selectedElement->unselect();

  if (!_selectionBase || _selectionBase->hasChild(element) == false)
    _selectionBase = element->getParent();

  _selectedElement = element;
  _selectedElement->select();
}
void Selector::select(GUIElement &element)
{
  select(&element);
}

void Selector::next()
{
  if (!_selectionBase || _selectionBase->hasChildren() == false) return;

  if (!_selectedElement) _selectedElement = _selectionBase->getChild(0);
  else if (_selectionBase->hasChild(_selectedElement) == false) return;

  uint16_t selectIndex = _selectionBase->findChildIndex(_selectedElement) + 1;

  if (selectIndex >= _selectionBase->childrenCount()) return;
  GUIElement *selectElement = _selectionBase->getChild(selectIndex);

  while (selectElement->isVisible() == false || selectElement->isSelecable() == false)
  {
    selectIndex++;
    if (selectIndex >= _selectionBase->childrenCount()) return;
    selectElement = _selectionBase->getChild(selectIndex);
  }
  select(selectElement);
}

void Selector::prev()
{
  if (!_selectionBase || _selectionBase->hasChildren() == false) return;
  
  if (!_selectedElement) _selectedElement = _selectionBase->getChild(0);
  else if (_selectionBase->hasChild(_selectedElement) == false) return;

  uint16_t selectIndex = _selectionBase->findChildIndex(_selectedElement);

  if (selectIndex <= 0) return;
  GUIElement *selectElement = _selectionBase->getChild(selectIndex - 1);

  while (selectElement->isVisible() == false || selectElement->isSelecable() == false)
  {
    selectIndex--;
    if (selectIndex <= 0) return;
    selectElement = _selectionBase->getChild(selectIndex - 1);
  }
  select(selectElement);
}

void Selector::enter(GUIElement *base)
{
  if (base->hasChildren() == false) return;
  select(base->getChild(0));
}
void Selector::enter(GUIElement &base)
{
  select(&base);
}
void Selector::enter()
{
  if (!_selectedElement) return;
  enter(_selectedElement);
}

void Selector::back()
{
  if (_selectionBase->hasParent() == false) return;
  select(_selectionBase);
}

const GUIElement &Selector::getSelected() const
{
  return _selectedElement;
}