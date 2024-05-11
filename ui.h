#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735

class ST7735
{

public:
    Adafruit_ST7735 tft; // = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

    ST7735(int TFT_CS, int TFT_DC, int TFT_RST) : tft(TFT_CS, TFT_DC, TFT_RST)
    {
        Serial.println("Initializing ST7735");
        tft.initR(INITR_BLACKTAB); // Init ST7735S chip, black tab
        Serial.println("ST7735 initialized");
    }

    void setBgColor(uint16_t color)
    {
        tft.fillScreen(color);
    }
    void setBgColor(uint8_t r, uint8_t g, uint8_t b)
    {
        tft.fillScreen(tft.color565(r, g, b));
    }
};

// Utils
struct Coord
{
    int x, y;
};

class Box
{

public:
    Coord coord;
    int width, height;
    Box(Coord coord, int width, int height) : coord(coord), width(width), height(height)
    {
    }
    Box(int x, int y, int width, int height) : coord({x, y}), width(width), height(height)
    {
    }
    Box(int width, int height) : coord({0, 0}), width(width), height(height)
    {
    }
    Box(Coord c1, Coord c2) : coord(coord), width(c2.x - c1.x), height(c2.y - c1.y)
    {
    }
};

class Font
{

public:
    int size;
    uint16_t color;
    Font(int size) : size(size), color(ST7735_BLACK)
    {
    }
    Font(int size, uint16_t color) : size(size), color(color)
    {
    }
};

// Widgets
class Text
{

public:
    const String text;
    Font font;
    Text(String text, Font font) : text(text), font(font)
    {
    }

    void draw(ST7735 tft, Coord coord)
    {
        tft.tft.setCursor(coord.x, coord.y);
        tft.tft.setTextColor(font.color);
        tft.tft.setTextSize(font.size);
        tft.tft.println(text);
    }
};