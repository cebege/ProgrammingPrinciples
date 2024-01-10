#include "Level.h"
#include <iostream>
using namespace std;

class Game
{
private:
	bool gameOver;
	Player player;
	Level level;

public:
	Game();
	~Game();

	bool load();
	void run();

	bool isGameOver();

private:
	bool update();
	void draw();



};