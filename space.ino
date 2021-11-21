#include "display.h"
#include "game.h"

const int potPin = A0;
const int ledPin = 4;
const int buttonPin = 6;

const int fps = 25;
const int frameDelay = 1000 / fps;

enum state {main_menu, in_game, game_over};
state currentState;

Game game(dWidth);

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  oledSetup();
  currentState = main_menu;
}

void loop() {
  if (currentState == main_menu) {
    drawMenu();
    if (digitalRead(buttonPin)) currentState = in_game;     // start game on button press
  }
  else if (currentState == in_game){
    game.update();
    drawGame(game.getGridPtr(), game.getBottomRowIndex(), game.getEnemyAltitude(), enemySpacing, game.getGridOffset_x());
    delay(frameDelay);
  }
  else {
    // TODO : game over
  }
}
