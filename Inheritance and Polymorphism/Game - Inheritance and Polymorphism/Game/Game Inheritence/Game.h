#include "Level.h"
#include "Player.h"


class Game
{
	Player player1;
	Level level1;
	bool gameOver;
	bool userQuit;

public:
	Game();
	~Game();

	bool load();
	void Run();

	bool isGameOver();
	bool didUserQuit() { return userQuit; }
	int getPlayerLives() { return player1.GetLive(); }


private:
	bool Update();
	void Draw();

	bool HandleCollision(int newPlayerX, int newPlayerY);


};
