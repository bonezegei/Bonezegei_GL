
/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __BGL_BUTTON_H_INCLUDED__
#define __BGL_BUTTON_H_INCLUDED__

#include <Bonezegei_Utility.h>
#include "bonezegei_object.h"

class BGL_Button : public Bonezegei_Object {
public:
  BGL_Button(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r)
    : Bonezegei_Object(GL_TYPE_BUTTON, GL, Parent, ID, r) {
  }

  virtual void setText(const char *str) {}
  virtual void setFont(FONT_TYPE fnt) {}
  virtual void setCallBack(void(*cb)(void)) {}
  virtual void setVisible(int8_t v){}

  uint32_t color;
  uint32_t color_clicked;
  char text[32];
  bool clicked;
  Point offset;

  FONT_TYPE font;
  void(*callback)(void) = NULL;
};


#endif