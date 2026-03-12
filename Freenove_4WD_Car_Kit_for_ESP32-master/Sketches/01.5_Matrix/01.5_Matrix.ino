/**********************************************************************
  Product     : Freenove 4WD Car for ESP32
  Description : Use led matrix.
  Auther      : www.freenove.com
  Modification: 2024/08/12
**********************************************************************/

#include "Freenove_VK16K33_Lib_For_ESP32.h"

#define EMOTION_ADDRESS 0x71
#define EMOTION_SDA     13
#define EMOTION_SCL     14

Freenove_ESP32_VK16K33 matrix = Freenove_ESP32_VK16K33();

byte x_array[][8] = {//Put the data into the left LED matrix
  //////////////////////////////////////////////
  0x00,0x00,0x00,0x5C,0xAA,0x62,0x1C,0x00,
  0x00,0x00,0x00,0x5C,0xA2,0x62,0x00,0x00,
  0x00,0x00,0x40,0xB8,0x64,0x02,0x18,0x00,
  0x00,0x04,0x42,0xB8,0x6C,0x22,0x1C,0x00,//---------x
  //////////////////////////////////////////////
};

byte y_array[][8] = {//Put the data into the right LED matrix
  //////////////////////////////////////////////
  0x00,0x00,0x00,0x3A,0x55,0x46,0x38,0x00,
  0x00,0x00,0x00,0x3A,0x45,0x46,0x00,0x00,
  0x00,0x00,0x02,0x1D,0x26,0x40,0x18,0x00,
  0x00,0x20,0x42,0x1D,0x36,0x44,0x38,0x00,//---------y
  /////////////////////////////////////////////////
};

void setup()
{
  matrix.init(EMOTION_ADDRESS, EMOTION_SDA, EMOTION_SCL);
  matrix.setBlink(VK16K33_BLINK_OFF);
  Serial.begin(9600);
  Serial.println("setting up");
}

void loop()
{
  Serial.println("looping");
  int count = sizeof(x_array) / sizeof(x_array[0]);
  for (int i = 0; i < count; i++)
  {
    Serial.println("blinking");
    matrix.showStaticArray(x_array[i], y_array[i]);
    delay(500);
  }
}
