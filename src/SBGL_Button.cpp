/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/

#include "BGL_Button.h"
#include "SBGL_Button.h"
#include "Bonezegei_GL.h"
#include "bonezegei_gl_default.h"

SBGL_Button::SBGL_Button(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r)
  : BGL_Button(GL, Parent, ID, r) {
  sprintf(text, "Button%d", ID);
  font = GL_FONT_BUTTON;
  color = GL_COLOR_BUTTON;
  color_clicked = GL_COLOR_BUTTTON_CLICKED;
  clicked = 0;
  callback = &default_callback;
}

void SBGL_Button::draw() {

  if (!visible) return;

  Rect r= rect + offset;
  gl->display->setFont(font);
  if (clicked) {
    gl->display->drawRectangle(true, rect, crect, color_clicked);
    gl->display->drawText(crect, r, true, text, color);
    gl->display->drawRectangle(rect, crect, color);
  } else {
    gl->display->drawRectangle(true, rect, crect, color);
    gl->display->drawText(crect, r, true, text, color_clicked);
  }
  Bonezegei_Object::draw();
}

bool SBGL_Button::onEvent(SystemEvent event) {

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


void SBGL_Button::setText(const char *str) {
  sprintf(text, "%s", str);
}
void SBGL_Button::setFont(FONT_TYPE fnt) {
  font = fnt;
}

void SBGL_Button::setCallBack(void (*cb)(void)) {
  callback = cb;
}

void SBGL_Button::setVisible(int8_t v) {
  visible = v;
}