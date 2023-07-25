/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __BONEZEGEI_GL_H_INCLUDED__
#define __BONEZEGEI_GL_H_INCLUDED__

#define GL_COLOR_CONTAINER 0XFFFFFF
#define GL_COLOR_BUTTON 0x008080
#define GL_COLOR_BUTTTON_CLICKED 0xFFFFFF
#define GL_COLOR_TEXTBOX_BACKGROUND 0xffffff
#define GL_COLOR_TEXTBOX_FONT 0x0

#define GL_FONT_BUTTON FONT_ARIAL_12




#include <Bonezegei_Utility.h>

#include "BGL_Container.h"
#include "BGL_Button.h"
#include "BGL_TextBox.h"
#include "BGL_ButtonBitmap.h"


class Bonezegei_Object;
class BGL_Container;
class BGL_Button;
class BGL_TextBox;
class BGL_ButtonBitmap;

class Bonezegei_GL {
public:
  Bonezegei_GL() {
  }

  virtual void drawAll() {}

  virtual BGL_Container *addContainer(Bonezegei_Object *Parent, Rect r, uint16_t ID);
  virtual BGL_Button *addButton(Bonezegei_Object *Parent, Rect r, uint16_t ID);
  virtual BGL_TextBox *addTextBox(Bonezegei_Object *Parent, Rect r, uint16_t ID);
  virtual BGL_ButtonBitmap *addButtonBitmap(Bonezegei_Object *Parent, Rect r, uint16_t ID);
  
  virtual bool onEvent(SystemEvent event);
  virtual bool postEvent(SystemEvent event);

  virtual bool getInput();

  Bonezegei_Display *display;
  Bonezegei_Input *input;
  Bonezegei_Event *event;
};

#endif