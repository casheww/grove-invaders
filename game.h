
const int gridWidth = 10;
const int gridHeight = 8;
const int enemySpacing = 8;         // pixels
const int initialMoveDelay = 4;     // updates

class Game {
  public:
    Game(int displayWidth);
    void update();
    bool checkGameOver();

    bool* getGridPtr();
    int getBottomRowIndex();
    int getEnemyAltitude();
    int getGridOffset_x();
    
  private:
    int _screenCellWidth;
  
    // enemies
    void _gridSetup();
    bool _checkSideCollision();
    bool _grid[gridWidth][gridHeight];
    int _enemyAltitude;
    int _bottomRow;
    int _updatesFromLastMove;
    int _moveDelay;
    int _gridOffset_x;
    int _enemyDirection;
};
