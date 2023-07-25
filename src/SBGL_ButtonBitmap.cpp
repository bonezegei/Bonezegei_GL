/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/

#include "BGL_ButtonBitmap.h"
#include "SBGL_ButtonBitmap.h"
#include "Bonezegei_GL.h"

void SBGL_default_callback() {
}

SBGL_ButtonBitmap::SBGL_ButtonBitmap(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r)
  : BGL_ButtonBitmap(GL, Parent, ID, r) {
 // bmp = (Bitmap *)&BitmapClose;
  color = GL_COLOR_BUTTON;
  color_clicked = GL_COLOR_BUTTTON_CLICKED;
  clicked = 0;
  callback = &SBGL_default_callback;
  offset = Point(0, 0);
}

void SBGL_ButtonBitmap::draw() {
  if (!visible) return;



  int x = rect.x1 + ((rect.x2 - rect.x1) / 2) - ((bmp.xbytes * 8) / 2) + offset.x;
  int y = rect.y1 + ((rect.y2 - rect.y1) / 2) - (bmp.yheight / 2) + offset.y;
  Point p(x, y);

  if (clicked) {
    gl->display->drawRectangle(true, rect, crect, color_clicked);
    gl->display->drawBitmap(crect, p, bmp, color);
    gl->display->drawRectangle(rect, crect, color);
  } else {
    gl->display->drawRectangle(true, rect, crect, color);
    gl->display->drawBitmap(crect, p, bmp, color_clicked);
  }
  Bonezegei_Object::draw();
}

bool SBGL_ButtonBitmap::onEvent(SystemEvent event) {
  if (event.Event_Type == ET_INPUT) {

    if (event.Input_Type == SCREEN_CLICKED_DOWN) {
      // Serial.println("BTN CLICKED DOWN");
      clicked = 1;
      if (eventOccur != _eventOccur) {
        _eventOccur = eventOccur;
        this->draw();
        //Serial.println("EVE");
      }
    }

    if (event.Input_Type == SCREEN_CLICKED_UP) {
      //Serial.println("BTN CLICKED DOWN");
    }
  }

  else if (event.Event_Type == ET_NONE) {
    clicked = 0;
    if (eventOccur != _eventOccur) {
      _eventOccur = eventOccur;
      this->draw();
      this->callback();
      //Serial.println("EVE END");
    }
  }

  Bonezegei_Object::onEvent(event);
  return parent ? parent->onEvent(event) : false;
}

void SBGL_ButtonBitmap::setBitmap(Bitmap b) {
  // realloc(bmp.data, (b.xbytes*b.yheight));
  bmp = b;
  //bmp.data = (char *)malloc(b.xbytes*b.yheight);
  //bmp.data = b.data;
}

void SBGL_ButtonBitmap::setCallBack(void (*cb)(void)) {
  callback = cb;
}

void SBGL_ButtonBitmap::setVisible(int8_t v) {
  visible = v;
}

