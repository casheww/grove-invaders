#include "display.h"
#include "game.h"

Game::Game(int displayWidth) {
  _displayWidth = displayWidth;
  _screenCellWidth = displayWidth / enemySpacing;   // maximum grid width the screen could accommodate
  
  _gridSetup();
  _enemyAltitude = gridHeight - 1;
  _bottomRow = gridHeight;
  _updatesFromLastMove = 0;
  _moveDelay = initialMoveDelay;
  _gridOffset_x = 0;
  _enemyDirection = 1;    // enemies start moving right. Left is -1

  _playerPos = displayWidth / 2;
  _projectileAlive = false;
}

void Game::update(float potFloat, bool buttonPressed) {
  /* TODO
   * change _bottomRow on row depletion, like a circular queue
   *    also fill what is now the top row
   * shoot when button is pressed
   */

  // set player's lateral position - lerp potentiometer reading
  _playerPos = _displayWidth * potFloat;
  
  // player shooting
  if (buttonPressed && !_projectileAlive) {
    _shoot();
    _projectileAlive = true;
  }
  else {
    _updateProjectile();
  }

  _moveEnemies();
}

void Game::_gridSetup() {
  // fill grid with enemies
  for (int y = 0; y < gridHeight; y++) {
    for (int x = 0; x < gridWidth; x++) {
      _grid[x][y] = true;
    }
  }
}

void Game::_shoot() {
  _projectile[0] = _playerPos;
  _projectile[1] = playerVertices[2][1];    // y pos of top of player triangle
}

void Game::_moveEnemies() {
  if (_moveDelay < _updatesFromLastMove) {
    _gridOffset_x += enemySpacing * _enemyDirection / 2;
    _updatesFromLastMove = 0;
  }
  else { _updatesFromLastMove++; }

  // make enemies bounce off edges
  if (_checkSideCollision()) {
    setLED(true);

    _enemyAltitude -= 1;
    _moveDelay *= 0.7;
    _enemyDirection *= -1;
  }
  else { setLED(false); }
}

void Game::_updateProjectile() {
  if (_projectile[1] < 0) {
    _projectileAlive = false;
  }
  else {
    // move projectile upwards on the screen -> decrease y pos
    _projectile[1] = _projectile[1] - projectileSpeed;
  }
}

bool Game::_checkSideCollision() {
  int left = 0;
  int right = gridWidth - 1;
  
  // sign of direction
  int sign = _enemyDirection < 0 ? -1 : (_enemyDirection == 0 ? 0 : 1);

  int closest;      // get x index of the enemy furthest forward in the direction of travel

  int x = sign == 1 ? right : left;     // start scan on target side
  while (sign == 1 && x >= left ||
        sign == -1 && x <= right) {
    for (int y = 0; y < gridHeight; y++) {
      if (_grid[x][y]) {
        closest = x;
        goto closestBreak;
      }
    }
  }
  closestBreak:

  if (sign == 1) {
    return _gridOffset_x / enemySpacing + (closest + 1) * sign >= _screenCellWidth;
  }
  else {
    return _gridOffset_x / enemySpacing + (closest + 1) * sign <= 0;
  }
}

bool Game::checkGameOver() {
  return _enemyAltitude <= 0;
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

int Game::getPlayerX() {
  return _playerPos;
}

int* Game::getProjectilePtr() {
  return &_projectile[0];
}
