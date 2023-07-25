/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/

#ifndef __BONEZEGEI_OBJECT_H_INCLUDED__
#define __BONEZEGEI_OBJECT_H_INCLUDED__


#include <Bonezegei_Utility.h>
#include <Bonezegei_List.h>

#include "bonezegei_event.h"

enum GL_TYPES {
  GL_TYPE_OBJECT = 0,
  GL_TYPE_CONTAINER,
  GL_TYPE_TEXT_BOX,
  GL_TYPE_BUTTON,
  GL_TYPE_BUTTON_BITMAP,
  GL_TYPE_BITMAP
};


class Bonezegei_GL;

class Bonezegei_Object : public Bonezegei_Event {
public:

  Bonezegei_Object(uint8_t Type, Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r)
    : parent(0) {
    type = Type;
    gl = GL;
    id = ID;
    rect = r;
    visible = 1;
    event = 0;
    _event = 0;
    redraw = 0;

    if (Parent) {
      Parent->addChild(this);
      crect = Parent->rect;
      rect = rect + crect.p1;
    }
  }

  virtual void addChild(Bonezegei_Object *ch) {
    if (ch) {
      ch->remove();
      ch->parent = this;
      child.push_back(ch);
    }
  }

  virtual void remove() {
    if (parent) {
      parent->removeChild(this);
    }
  }

  virtual void removeChild(Bonezegei_Object *ch) {
    Bonezegei_List<Bonezegei_Object *>::iterator obj = child.begin();
    for (; obj != child.end(); ++obj) {
      if ((*obj) == ch) {
        (*obj)->parent = 0;
        child.erase(obj);
      }
    }
  }

  Bonezegei_Object *getObject(Point p) {
    Bonezegei_Object *target = 0;
    Bonezegei_List<Bonezegei_Object *>::iterator obj = child.getLast();
    if (visible) {
      while (obj != child.end()) {
        target = (*obj)->getObject(p);
        if (target) {
          return target;
        }
        --obj;
      }
    }
    if (rect.isPointInside(p) && visible) {
      target = this;
    }
    return target;
  }

  virtual bool bringToFront(Bonezegei_Object *ch) {
    Bonezegei_List<Bonezegei_Object *>::iterator obj = child.begin();
    for (; obj != child.end(); ++obj) {
      if ((*obj) == ch) {
        child.erase(obj);
        child.push_back(ch);
        return true;
      }
    }
    return false;
  }

  virtual void updatePosition(Point p) {
    rect = rect + p;
    Bonezegei_List<Bonezegei_Object *>::iterator obj = child.begin();
    for (; obj != child.end(); ++obj) {
      (*obj)->crect = rect;
      (*obj)->rect = (*obj)->rect + p;
    }
  }

  virtual void updateChildPosition(Point p) {
    Bonezegei_List<Bonezegei_Object *>::iterator obj = child.begin();
/*       Serial.print("parent ");
      Serial.print( " x1:");
      Serial.print( rect.x1);
      Serial.print( " y1:");
      Serial.print(rect.y1);
      Serial.print( " x2:");
      Serial.print( rect.x2);
      Serial.print( " y2:");
      Serial.println(rect.y2); 
    int a =0;*/
    for (; obj != child.end(); ++obj) {
      (*obj)->rect = (*obj)->rect + p;
/*       Serial.print(a);
      Serial.print( " x1:");
      Serial.print( (*obj)->rect.x1);
      Serial.print( " y1:");
      Serial.print( (*obj)->rect.y1);
      Serial.print( " x2:");
      Serial.print( (*obj)->rect.x2);
      Serial.print( " y2:");
      Serial.print( (*obj)->rect.y2);

      Serial.print( "\t Crect");
      Serial.print( " cx1:");
      Serial.print( (*obj)->crect.x1);
      Serial.print( " cy1:");
      Serial.print( (*obj)->crect.y1);
      Serial.print( " cx2:");
      Serial.print( (*obj)->crect.x2);
      Serial.print( " cy2:");
      Serial.println( (*obj)->crect.y2);

      a++; */
    }
    // Serial.println(" ");
  }

  virtual void draw() {
    if (!visible) {
      return;
    }
    Bonezegei_List<Bonezegei_Object *>::iterator obj = child.begin();
    for (; obj != child.end(); ++obj) {
      (*obj)->draw();
    }
  }

  virtual bool onEvent(SystemEvent event) {

    if (event.Event_Type == ET_INPUT) {
      eventOccur = 1;
    } else {
      eventOccur = 0;
    }

    return true;
  }



  Bonezegei_List<Bonezegei_Object *> child;
  Bonezegei_Object *parent;
  Bonezegei_GL *gl;

  Rect rect;
  Rect crect;
  uint16_t id;
  uint8_t type;
  uint8_t visible;

  int8_t eventOccur;
  int8_t _eventOccur;
  int8_t redraw;
};


#endif