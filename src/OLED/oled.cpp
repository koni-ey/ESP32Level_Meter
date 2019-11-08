#include <Wire.h> 
#include <Arduino.h>
#include "oled.h"
#include <SSD1306Wire.h>

SSD1306Wire oled1(0x3c, 9, 10, GEOMETRY_128_32);

void OLED::oledinit(){
    oled1.init();
    oled1.flipScreenVertically();
    oled1.setFont(ArialMT_Plain_16);
}

void OLED::show(String line1, String line2){
    oled1.clear();
    oled1.drawString(0,0,line1);
    oled1.drawString(0,16,line2);
    oled1.display();
}