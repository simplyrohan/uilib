#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include "math.h"

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

// Convert 24-bit RGB color to 16-bit color
uint16_t rgb565(const unsigned long rgb)
{
    uint16_t R = (rgb >> 16) & 0xFF;
    uint16_t G = (rgb >> 8) & 0xFF;
    uint16_t B = (rgb) & 0xFF;

    uint16_t ret = (R & 0xF8) << 8; // 5 bits
    ret |= (G & 0xFC) << 3;         // 6 bits
    ret |= (B & 0xF8) >> 3;         // 5 bits

    return (ret);
}

unsigned countBits(unsigned long number)
{
    // log function in base 2
    // take only integer part
    Serial.println(number);
    return (int)(log(number) / log(2)) + 1;
}

unsigned long validateColor(unsigned long color)
{
    unsigned int bits = countBits(color);
    Serial.println(bits);
    if (bits == 16)
    {
        return color;
    }
    if (bits == 24)
    {

        return rgb565(color);
    }
}

class TFT
{
public:
    TFT(int cs, int dc, int rst) : display(cs, dc, rst){};
    TFT(int cs, int dc, int rst, int mosi, int sclk) : display(cs, dc, rst, mosi, sclk){};

    void begin()
    {
        display.initR(INITR_BLACKTAB);
        display.fillScreen(ST7735_BLACK);
    }

    void setTextColor(unsigned long color)
    {
        textColor = validateColor(color);
        draw();
    }

    void setBackgroundColor(unsigned long color)
    {
        backgroundColor = validateColor(color);
        draw();
    }

    void draw() {
        display.fillScreen(backgroundColor);
        display.setTextColor(textColor);
    }

    // private:
    Adafruit_ST7735 display;
    uint16_t backgroundColor = BLACK;
    uint16_t textColor = WHITE;
};