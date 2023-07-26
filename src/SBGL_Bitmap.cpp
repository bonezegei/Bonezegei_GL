/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#include "Bonezegei_GL.h"
#include "SBGL_Bitmap.h"

SBGL_Bitmap::SBGL_Bitmap(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r)
    : BGL_Bitmap(GL, Parent, ID, r) {
        color = GL_COLOR_BITMAP;
        color_background = GL_COLOR_BITMAP_BACKGROUND;
  }

void SBGL_Bitmap::draw() {
    if (!visible) return;
/*     gl->display->drawRectangle(true, rect, crect, 0x00ff00); */
    Point p(rect.x1,rect.y1);
    gl->display->drawBitmap(crect, p, bmp, color );

    Bonezegei_Object::draw();
  }

void SBGL_Bitmap::setVisible(int8_t v) {
    visible = v;
  }

void SBGL_Bitmap::setBitmap(Bitmap b){
     bmp = b;
  }

bool SBGL_Bitmap::onEvent(SystemEvent event) {
    return parent ? parent->onEvent(event) : false;
  }


