#include "Player.h"
#include "Level.h"

using namespace std;

class Game
{

private:
	bool mUserQuit;
	bool mGameOver;
	Player mPlayer;
	Level mLevel;

public:
	Game();
	~Game();

	bool load();
	void run();

	bool didUserQuit() { return mUserQuit; }
	bool isGameOver() { return mGameOver; }

	int getPlayerLives();

private:
	
	bool update();
	void draw();


	bool handleCollision(int newPlayerX, int newPlayerY);

};