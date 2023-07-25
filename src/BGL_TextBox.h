
/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __BGL_TEXTBOX_H_INCLUDED__
#define __BGL_TEXTBOX_H_INCLUDED__

#include "bonezegei_object.h"

class BGL_TextBox : public Bonezegei_Object {
public:
  BGL_TextBox(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r)
    : Bonezegei_Object(GL_TYPE_TEXT_BOX, GL, Parent, ID, r) {
  }
  virtual void draw() {}
  virtual void setText(char *str);
  virtual void setVisible(int8_t v) {}
  virtual void setFont(FONT_TYPE fnt) {}

  uint32_t color_background;
  uint32_t color_font;
  FONT_TYPE FONT;
};


#endif