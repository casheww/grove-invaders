#include <U8g2lib.h>
#include "display.h"
#include "game.h"

U8G2_SSD1306_128X64_NONAME_2_HW_I2C oled(U8G2_R2);

void oledSetup() {
  oled.begin();
}

void drawGame(bool* gridPtr, int bottomRow, int enemyAltitude, int enemySpacing, int xOffset) {
  oled.firstPage();
  do {
    int bottomRowDrawY = dHeight - enemyAltitude * enemySpacing;
    for (int y = 0; y < gridHeight; y++) {
      int drawY = bottomRowDrawY - (bottomRow - y) * enemySpacing;

      int drawX = xOffset;
      for (int x = 0; x < gridWidth; x++) {
        if ((*gridPtr) + x + y * gridWidth) {     // retrieve bool value from 2D array... jeez
          oled.drawPixel(drawX, drawY);
        }
        drawX += enemySpacing;
      }
    }
  } while (oled.nextPage());
}

void drawMenu() {
  oled.firstPage();
  do {
    oled.setFont(u8g2_font_7x13_mf);
    oled.drawStr(0, 10, "tiny ");
    oled.drawStr(0, 24, "space invaders");
    oled.setFont(u8g2_font_6x13O_mf);
    oled.drawStr(0, 45, "press button");
  } while (oled.nextPage());
}
