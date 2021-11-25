
const int gridWidth = 10;
const int gridHeight = 8;
const int enemySpacing = 8;           // pixels
const int initialMoveDelay = 4;       // updates
const int projectileSpeed = 4;        // pixels per update

class Game {
  public:
    Game(int displayWidth);
    void update(float potFloat, bool buttonPressed);
    bool checkGameOver();

    bool* getGridPtr();
    int getBottomRowIndex();
    int getEnemyAltitude();
    int getGridOffset_x();

    int getPlayerX();
    int* getProjectilePtr();
    
  private:
    int _displayWidth;
    int _screenCellWidth;
  
    // enemies
    void _gridSetup();
    void _moveEnemies();
    bool _checkSideCollision();
    bool _grid[gridWidth][gridHeight];
    int _enemyAltitude;
    int _bottomRow;
    int _updatesFromLastMove;
    int _moveDelay;
    int _gridOffset_x;
    int _enemyDirection;

    // player
    void _shoot();
    void _updateProjectile();
    int _playerPos;
    int _projectile[2];
    bool _projectileAlive;
    
};
