#include <U8g2lib.h>
#include "display.h"

U8G2_SSD1306_128X64_NONAME_2_HW_I2C oled(U8G2_R2);

void oledSetup() {
  oled.begin();
}

void drawGame(bool* gridPtr){
  // TODO 
  
  oled.firstPage();
  do {
    for (int y = 0; y < 64; y++) {
      for (int x = 0; x < 128; x+=10) {
        oled.drawPixel(x, y);
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
