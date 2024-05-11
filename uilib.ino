#include "ui.h"

#define TFT_CS A2
#define TFT_RST A1 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC A0

ST7735 tft(TFT_CS, TFT_DC, TFT_RST);

Text text("Hello, world!", Font(2));

void setup(void)
{
    Serial.begin(115200);

    // tft.initR(INITR_BLACKTAB); // Init ST7735S chip, black tab
    // tft.setBgColor(0, 0, 255); // Blue
    text.draw(tft, {0, 0});
}

void loop()
{
}