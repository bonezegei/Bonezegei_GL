/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __BGL_BITMAP_H_INCLUDED__
#define __BGL_BITMAP_H_INCLUDED__

#include "bonezegei_object.h"

class BGL_Bitmap : public Bonezegei_Object {
public:
  BGL_Bitmap(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r)
    : Bonezegei_Object(GL_TYPE_BITMAP, GL, Parent, ID, r) {
  }

  virtual void draw() {}
  virtual void setVisible(int8_t v) {} 
  virtual void setBitmap(Bitmap b){}

  uint32_t color;
  uint32_t color_background;
  Bitmap bmp;
};


#endif