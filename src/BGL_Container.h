/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __BGL_CONTAINER_H_INCLUDED__
#define __BGL_CONTAINER_H_INCLUDED__

#include "bonezegei_object.h"

class BGL_Container : public Bonezegei_Object {
public:
  BGL_Container(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r)
    : Bonezegei_Object(GL_TYPE_CONTAINER, GL, Parent, ID, r) {
  }

  virtual void draw() {}
  virtual void setVisible(int8_t v) {}
  uint32_t color;
};


#endif