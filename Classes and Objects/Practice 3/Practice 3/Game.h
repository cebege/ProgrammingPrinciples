#include "Level.h"
using namespace std;

class Game
{
private:
	bool gameOver;
	Player player;
	Level level;

public:
	Game(bool gameOver = false);
	~Game();

	void run();
	bool update();
	void draw();

	bool isGameOver();
	bool loadLevel();
	







};
