#include "Level.h"
using namespace std;

class Game
{
private:
	Level level;
	Player player;
	bool gameOver;

public:
	Game(bool gameOver = false);
	~Game();

	void draw();

	bool update();
	void run();
	bool load();
	bool isGameOver();
};