/*
  This Library is written for Bonezegei Graphics
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/
#ifndef __BONEZEGEI_GRAPHICS_H_INCLUDED__
#define __BONEZEGEI_GRAPHICS_H_INCLUDED__

#include <Bonezegei_Utility.h>
#include "Bonezegei_GL.h"
#include "SBonezegei_GL.h"

#define Button BGL_Button
#define Box BGL_Container
#define TextBox BGL_TextBox

SBonezegei_GL _GL;

class Bonezegei_Graphics {
public:
  Bonezegei_Graphics() {
  }

  void begin() {
    gl = &_GL;
  }

  void setDisplay(Bonezegei_Display *Display) {
    gl->display = Display;
    gl->display->begin();
    gl->display->setRotation(1);
    gl->display->setFont(FONT_ARIAL_14);
  }

  void setInput(Bonezegei_Input *Input) {
    gl->input = Input;
    gl->input->begin();
    gl->input->setRotation(1);
  }

  void drawUpdate() {
    gl->drawAll();
  }

  bool inputUpdate() {
    return gl->getInput();
  }


  SBonezegei_GL *gl;
};


#endif