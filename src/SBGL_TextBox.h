/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __SBGL_TEXTBOX_H_INCLUDED__
#define __SBGL_TEXTBOX_H_INCLUDED__

#include "BGL_TextBox.h"

class SBGL_TextBox : public BGL_TextBox {
public:
  SBGL_TextBox(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r);
  void setText(char *str);
  void draw();
  void setVisible(int8_t v);
  void setFont(FONT_TYPE fnt);
  bool onEvent(SystemEvent event);

  char *text;
};


#endif
