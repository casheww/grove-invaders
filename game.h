//class Game {
//  public:
//    Game();
//    bool* getGrid();
//  private:
//    void _gameSetup();
//    void _gridSetup();
//    static const int w;
//    static const int h;
//    bool _grid [w][h];
//    int gridAltitude;
//};

class Game {
  public:
    Game() {
      _gridSetup();
    }
  
    bool* getGrid() {
      return &_grid[0][0];
    }

  private:
    void _gameSetup() {
      _gridSetup();
      gridAltitude = 8;
    }

    void _gridSetup() {
      // fill grid with enemies
      for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
          _grid[x][y] = true;
        }
      }
    }

    static const int w = 16;
    static const int h = 8;
    bool _grid [w][h];
    int gridAltitude;
};
