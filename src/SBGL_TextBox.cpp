/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
*/

#include "BGL_TextBox.h"
#include "SBGL_TextBox.h"
#include "Bonezegei_GL.h"

SBGL_TextBox::SBGL_TextBox(Bonezegei_GL *GL, Bonezegei_Object *Parent, uint16_t ID, Rect r)
  : BGL_TextBox(GL, Parent, ID, r) {

  text = (char *) malloc(15);
  sprintf(text, "TextBox");

  color_background = GL_COLOR_TEXTBOX_BACKGROUND;
  color_font = GL_COLOR_TEXTBOX_FONT;
  FONT = FONT_ARIAL_12;
}

void SBGL_TextBox::setText(char *str) {
  realloc(text,strlen(str)+1);
  sprintf(text, "%s", str);
}

void SBGL_TextBox::draw() {
  if (!visible) return;

  gl->display->setFont(FONT);
  gl->display->drawRectangle(true, rect, crect, color_background);
  gl->display->drawText(true, rect, rect, (const char *)text, color_font);
  Bonezegei_Object::draw();
}

void SBGL_TextBox::setVisible(int8_t v) {
  visible = v;
}

void SBGL_TextBox::setFont(FONT_TYPE fnt) {
  FONT = fnt;
}

bool SBGL_TextBox::onEvent(SystemEvent event) {

  Bonezegei_Object::onEvent(event);
  return parent ? parent->onEvent(event) : false;
}
