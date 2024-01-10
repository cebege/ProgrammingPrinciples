#include "Player.h"
#include <string>
#include <vector>
using namespace std;

class PlaceableActor;


class Level
{
	char* plevel;
	int height;
	int width;

	vector<PlaceableActor*> m_pActors;

public:
	Level();
	~Level();

	bool LoadLevel(string levelName, int* playerX, int* playerY);
	void Draw();
	PlaceableActor* UpdateActors(int x, int y);

	bool IsSpace(int x, int y);
	bool IsWall(int x, int y);

	int GetHeight() { return height; }
	int GetWidth() { return width; }
	int GetIndex(int x, int y);

	static constexpr char WAL = (char)219;

private:
	bool Convert(int* playerX, int* playerY);

};
