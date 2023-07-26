/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __SBONEZEGEI_GL_H_INCLUDED__
#define __SBONEZEGEI_GL_H_INCLUDED__

#define GL_COLOR_CONTAINER 0XFFFFFF


#include "bonezegei_object.h"
#include "Bonezegei_GL.h"

#include "SBGL_Container.h"
#include "SBGL_Button.h"
#include "SBGL_TextBox.h"
#include "SBGL_ButtonBitmap.h"
#include "SBGL_Bitmap.h"


class SBonezegei_GL : public Bonezegei_GL, public Bonezegei_Object {
public:
  SBonezegei_GL()
    : Bonezegei_Object(GL_TYPE_OBJECT, 0, 0, 0, Rect(0, 0, 320, 240)) {
    focusObj = this;
  }

  void drawAll() {
    draw();
  }

  BGL_Container *addContainer(Bonezegei_Object *Parent, Rect r, uint16_t ID) {
    BGL_Container *c = new SBGL_Container(this, Parent ? Parent : this, ID, r);
    return c;
  }

  BGL_Button *addButton(Bonezegei_Object *Parent, Rect r, uint16_t ID) {
    BGL_Button *b = new SBGL_Button(this, Parent ? Parent : this, ID, r);
    return b;
  }

  BGL_TextBox *addTextBox(Bonezegei_Object *Parent, Rect r, uint16_t ID) {
    BGL_TextBox *t = new SBGL_TextBox(this, Parent ? Parent : this, ID, r);
    return t;
  }

  BGL_ButtonBitmap *addButtonBitmap(Bonezegei_Object *Parent, Rect r, uint16_t ID) {
    BGL_ButtonBitmap *b = new SBGL_ButtonBitmap(this, Parent ? Parent : this, ID, r);
    return b;
  }

  BGL_Bitmap *addBitmap(Bonezegei_Object *Parent, Rect r, uint16_t ID){
    BGL_Bitmap *b = new SBGL_Bitmap(this, Parent ? Parent : this, ID, r);
    return b;
  }

  bool onEvent(SystemEvent event) {
    return true;
  }
  bool postEvent(SystemEvent event) {
    return true;
  }

  bool getInput() {
    if (input->getPress()) {
      focusObj = getObject(input->point);
      SystemEvent e;
      e.Event_Type = ET_INPUT;
      e.Input_Type = SCREEN_CLICKED_DOWN;
      e.x = input->_x;
      e.y = input->_y;

      focusObj->onEvent(e);
      //focusObj->draw();
      /* 
      Serial.print("ID: ");
      Serial.print(focusObj->id);
      Serial.print(" x: ");
      Serial.print(e.x);
      Serial.print(" y: ");
      Serial.println(e.y); */
      return 1;
    } else {
      SystemEvent e;
      e.Event_Type = ET_NONE;
      focusObj->onEvent(e);
      //focusObj->draw();
    }

    return 0;
  }

  Bonezegei_Object *focusObj;
};

#endif