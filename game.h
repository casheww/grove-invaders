
const int gridWidth = 16;
const int gridHeight = 8;
const int enemySpacing = 8;         // pixels
const int initialMoveDelay = 1000;  // time between enemies' lateral movement at start of game

class Game {
  public:
    Game();
    void update();

    bool* getGridPtr();
    int getBottomRowIndex();
    int getEnemyAltitude();
    int getGridOffset_x();
    
  private:
    // enemies
    void _gridSetup();
    bool _grid[gridWidth][gridHeight];
    int _bottomRow;
    int _enemyAltitude;
    int _msForMove;
    int _gridOffset_x;
};
