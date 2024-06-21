#include "ui.h"

#define TFT_CS 10
#define TFT_RST -1 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 8

TFT tft = TFT(TFT_CS, TFT_DC, TFT_RST);

void setup(void)
{
    Serial.begin(115200);

    tft.begin();
    delay(2000);
    tft.setBackgroundColor(0xeb34c3);
}

void loop()
{
    
}