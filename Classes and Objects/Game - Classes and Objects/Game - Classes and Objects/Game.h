#include "Level.h"
#include "Player.h"


class Game
{
	Player player1;
	Level level1;
	bool gameOver;

public:
	Game();
	~Game();

	bool load();
	void Run();

	bool isGameOver();

private:
	bool Update();
	void Draw();
};
