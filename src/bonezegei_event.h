#include <sys/types.h>
/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __BONEZEGEI_EVENT_H_INCLUDED__
#define __BONEZEGEI_EVENT_H_INCLUDED__



class Bonezegei_Object;

enum INPUT_EVENT {
  SCREEN_CLICKED_DOWN = 0,
  SCREEN_CLICKED_UP,
};

enum UI_EVENT {
  UI_BUTTON_CLICK_DOWN,
  UI_BUTTON_CLICK_UP
};


enum EVENT_TYPE {
  ET_NONE = 0,  // Waiting for Event
  ET_USER,
  ET_UI,
  ET_INPUT
};

struct SystemEvent {
  Bonezegei_Object* obj;

  int8_t Event_Type;
  int8_t UI_Type;
  int8_t Input_Type;

  int16_t x, y;
};


class Bonezegei_Event {
public:
  virtual bool onEvent(SystemEvent event) {
    return true;
  }

  uint8_t event;
  uint8_t _event;
};


#endif