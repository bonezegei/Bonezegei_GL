/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __SBGL_BUTTON_H_INCLUDED__
#define __SBGL_BUTTON_H_INCLUDED__

#include "BGL_Button.h"

class SBGL_Button : public BGL_Button {
public:
  SBGL_Button(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r);

  void draw();
  bool onEvent(SystemEvent event);
  void setText(const char *str);
  void setFont(FONT_TYPE fnt);
  void setCallBack(void (*cb)(void));
  void setVisible(int8_t v);


};


#endif