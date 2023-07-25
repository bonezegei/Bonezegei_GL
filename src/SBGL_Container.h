/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __SBGL_CONTAINER_H_INCLUDED__
#define __SBGL_CONTAINER_H_INCLUDED__

#include "BGL_Container.h"


class SBGL_Container : public BGL_Container {
public:
  SBGL_Container(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r)
    : BGL_Container(GL, Parent, ID, r) {
  }

  void draw() {
    if (!visible) return;
    gl->display->drawRectangle(true, rect, crect, color);
    Bonezegei_Object::draw();
  }
  void setVisible(int8_t v) {
    visible = v;
  }

  bool onEvent(SystemEvent event) {
    return parent ? parent->onEvent(event) : false;
  }
};


#endif