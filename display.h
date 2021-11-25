const int ledPin = 4;
const int buzzerPin = 5;
const int dWidth = 128;
const int dHeight = 64;

const int playerVertices[3][2] = { {-3, 63}, {3, 63}, {0, 58} };

void setLED(bool _on);
void playBuzzer(int updates, int pitch);
void updateBuzzer();

void outSetup(int gWidth, int gHeight);
void drawGame(bool* gridPtr, int bottomRow, int enemyAltitude, int enemySpacing, int enemiesX, int playerX, int* projectilePtr);
void drawMenu();
void drawGameOver();
