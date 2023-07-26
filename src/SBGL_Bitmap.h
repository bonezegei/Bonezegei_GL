/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __SBGL_BITMAP_H_INCLUDED__
#define __SBGL_BITMAP_H_INCLUDED__

#include "BGL_Bitmap.h"


class SBGL_Bitmap : public BGL_Bitmap {
public:
  SBGL_Bitmap(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r);
  void draw();
  void setVisible(int8_t v);

  void setBitmap(Bitmap b);
  bool onEvent(SystemEvent event);
};


#endif