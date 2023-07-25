
/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __BGL_BUTTONBITMAP_H_INCLUDED__
#define __BGL_BUTTONBITMAP_H_INCLUDED__

#include <Bonezegei_Utility.h>
#include "bonezegei_object.h"

class BGL_ButtonBitmap : public Bonezegei_Object {
public:
  BGL_ButtonBitmap(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r)
    : Bonezegei_Object(GL_TYPE_BUTTON_BITMAP, GL, Parent, ID, r) {
  }

  virtual void setBitmap(Bitmap b){}
  virtual void setCallBack(void(*cb)(void)) {}
  virtual void setVisible(int8_t v){}

  uint32_t color;
  uint32_t color_clicked;
  bool clicked;
  Point offset;
  Bitmap bmp;

  void(*callback)(void) = NULL;
};


#endif