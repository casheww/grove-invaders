#include <U8g2lib.h>
#include "display.h"

U8G2_SSD1306_128X64_NONAME_2_HW_I2C oled(U8G2_R2);

int gridWidth, gridHeight;
int buzzerUpdateCounter = 0;

void outSetup(int gWidth, int gHeight) {
  oled.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  gridWidth = gWidth;
  gridHeight = gHeight;
}

void setLED(bool _on) {
  digitalWrite(ledPin, _on);
}

void playBuzzer(int updates, int pitch) {
  analogWrite(buzzerPin, pitch);
  buzzerUpdateCounter = updates;
  
}

void updateBuzzer() {
  if (buzzerUpdateCounter > 0) {
    buzzerUpdateCounter--;
  }
  else {
    analogWrite(buzzerPin, 0);
  }
}

void drawEnemies(bool* gridPtr, int bottomRow, int enemyAltitude, int enemySpacing, int enemiesX);
void drawPlayer(int x);
void drawProjectile(int x, int y);

void drawGame(bool* gridPtr, int bottomRow, int enemyAltitude, int enemySpacing, int enemiesX, int playerX, int* projectilePtr) {
  oled.firstPage();
  do {
    drawEnemies(gridPtr, bottomRow, enemyAltitude, enemySpacing, enemiesX);
    drawPlayer(playerX);
    drawProjectile(*projectilePtr, *(projectilePtr + 1));
  } while (oled.nextPage());
}

void drawMenu() {
  oled.firstPage();
  do {
    oled.setFont(u8g2_font_t0_14_mf);
    oled.drawStr(0, 10, "tiny ");
    oled.drawStr(0, 24, "space invaders");
    oled.setFont(u8g2_font_6x13O_mf);
    oled.drawStr(0, 45, "press button");
  } while (oled.nextPage());
}

void drawGameOver() {
  oled.firstPage();
  do {
    oled.setFont(u8g2_font_t0_18_mf);
    oled.drawStr(0, 15, "game over");
    oled.setFont(u8g2_font_6x13O_mf);
    oled.drawStr(0, 45, "press button");
  } while (oled.nextPage());
}


// drawing the game scene:

void drawEnemies(bool* gridPtr, int bottomRow, int enemyAltitude, int enemySpacing, int enemiesX) {
  int bottomRowDrawY = dHeight - enemyAltitude * enemySpacing;
  for (int y = 0; y < gridHeight; y++) {
    int drawY = bottomRowDrawY - (bottomRow - y) * enemySpacing;

    int drawX = enemiesX;
    for (int x = 0; x < gridWidth; x++) {
      if ((*gridPtr) + x + y * gridWidth) {     // retrieve bool value from 2D array... jeez
        oled.drawPixel(drawX, drawY);
      }
      drawX += enemySpacing;
    }
  }
}

void drawPlayer(int x) {
  oled.drawTriangle(
    playerVertices[0][0] + x, playerVertices[0][1],
    playerVertices[1][0] + x, playerVertices[1][1],
    playerVertices[2][0] + x, playerVertices[2][1]
  );
}

void drawProjectile(int x, int y) {
  oled.drawPixel(x, y);
}
