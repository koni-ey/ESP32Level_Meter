#include <Arduino.h>
#include <Webserver/Webserver.h>
#include "OLED/oled.h"
#include "HCSR04/reader.h"


#define INTERRUPTPin 0

 myServer server;
 OLED myoled;
 reader myreader;
 bool inter = false;

 void IRAM_ATTR isr();

void setup()
{
  Serial.begin(115200);
  server.init();
  myoled.oledinit();
  myreader.init();
  pinMode(INTERRUPTPin, INPUT_PULLUP);
  attachInterrupt(INTERRUPTPin, isr, RISING);
}

void loop()
{
  myoled.show("Distanz: " + myreader.getDistance(), "Level: " + myreader.getLevel());
  server.handleClient(myreader.getDistance(), myreader.getLevel());
  if (inter){
    myoled.show("IP: ", server.getIp());
    delay(3000);
    inter = false;
  }
}

void IRAM_ATTR isr() {
 inter = true;
}

