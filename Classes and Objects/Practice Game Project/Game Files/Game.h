#ifndef _GAME_H_
#define _GAME_H_
#include "Level.h"

class Game
{
private:
	Player player; // usually player classes and other large members would be pointers.
	Level level;
	bool gameOver;

public:

	Game(); // constructor chaining?
	~Game();

	bool load();
	bool run();

	bool isGameOver();

private:

	bool update(); // only called internally by this class and its children.
	void draw(); //used for general operation and processing.
};



#endif
