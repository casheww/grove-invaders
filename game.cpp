#include "game.h"

Game::Game() {
  _gridSetup();
  _enemyAltitude = gridHeight - 1;
  _bottomRow = gridHeight;
  _msForMove = initialMoveDelay;
  _gridOffset_x = 0;
}

void Game::update() {
  /* TODO
   * change x-offset of enemy graphics after some time delay
   *    decrease said time delay on edge collision
   * change altitude of bottom row on edge collision
   * change _bottomRow on row depletion, like a circular queue
   *    also fill what is now the top row
   * check game over?
   */
}

bool* Game::getGridPtr() {
  return &_grid[0][0];
}

int Game::getBottomRowIndex() {
  return _bottomRow;
}

int Game::getEnemyAltitude() {
  return _enemyAltitude;
}

int Game::getGridOffset_x() {
  return _gridOffset_x;
}

void Game::_gridSetup() {
  // fill grid with enemies
  for (int y = 0; y < gridHeight; y++) {
    for (int x = 0; x < gridWidth; x++) {
      _grid[x][y] = true;
    }
  }
}
