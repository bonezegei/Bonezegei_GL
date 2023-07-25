/*
  Author: Bonezegei (Jofel Batutay)
  Date: July 2023 
  Bonezegei_GL Sample Beta
  
  ------------------------
  | PIN        |  ESP32  |
  |----------------------|
  | MOSI       |   23    | ILI9341|XPT2046 PIN
  | SCK        |   18    | ILI9341|XPT2046 PIN
  | MISO       |   19    | ILI9341|XPT2046 PIN
  | CS         |   4     | ILI9341 PIN
  | RST        |   16    | ILI9341 PIN
  | DC         |   17    | ILI9341 PIN
  |----------------------|
  | TS_CS      |   33    | XPT2046 PIN
  ------------------------

  LED of the LCD can be connected to the 3.3V with 100 Ohm resitory
  [ IMPORTANT ] Install with the dependencies
*/


#include <Bonezegei_ILI9341v2.h>
#include <Bonezegei_Utility.h>
#include <Bonezegei_XPT2046v2.h>

#include "Bonezegei_Graphics.h"

#define LCD_DC 17
#define LCD_CS 4
#define LCD_RST 16
#define TS_CS 33


//Display and Input Driver
Bonezegei_ILI9341v2 lcd(LCD_RST, LCD_CS, LCD_DC);
Bonezegei_XPT2046v2 ts(TS_CS);

//Declaration of the Bonezegei Graphics Library
Bonezegei_Graphics gfx;


//Container Box
BGL_Container *cont1;
//TextBox
BGL_TextBox *text1;
//Text Button
BGL_Button *btn1;


//Callback when button is clicked
void btn_callback() {
  Serial.println("BTN Clicked");
}

void setup() {
  Serial.begin(115200);

  //Initialize the GL and set the display and Input
  gfx.begin();
  gfx.setDisplay(&lcd);
  gfx.setInput(&ts);

  //Rectangles
  Rect RectCont1(0, 0, 320, 240);
  Rect RectTb(20,20,290,200);
  Rect RectBTN(40,160,140,190);

  //Container Set as Parent to other UI elements
  // param1 = 0 means set as parent otherwise  
  // param2 = Rectangle of the container
  // param3 = ID can be set to 0 
  cont1 = gfx.gl->addContainer(0, RectCont1, 0);
  
  text1 = gfx.gl->addTextBox(cont1, RectTb, 1);
  text1->setFont(FONT_ARIAL_10);
  text1->setText((const char*)"Lorem ipsum dolor sit amet consectetur adipiscing elit, urna consequat felis vehicula class ultricies mollis dictumst, aenean non a in donec nulla.");

  btn1= gfx.gl->addButton(cont1, RectBTN, 3);
  btn1->setText((const char*)"Button");
  btn1->setFont(FONT_ARIAL_14);
  btn1->setCallBack(btn_callback);

  //Draw ALL
  gfx.drawUpdate();
}

void loop() {

  gfx.inputUpdate();
  delay(5);
}
