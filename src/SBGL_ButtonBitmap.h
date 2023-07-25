/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __SBGL_BUTTONBITMAP_H_INCLUDED__
#define __SBGL_BUTTONBITMAP_H_INCLUDED__

#include "BGL_ButtonBitmap.h"

class SBGL_ButtonBitmap : public BGL_ButtonBitmap {
public:
  SBGL_ButtonBitmap(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r);

  void draw();
  bool onEvent(SystemEvent event);
  void setBitmap(Bitmap b);
  void setCallBack(void (*cb)(void));
  void setVisible(int8_t v);

};


#endif