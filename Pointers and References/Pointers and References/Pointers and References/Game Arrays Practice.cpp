#include <iostream>
#include <Windows.h>
#include <fStream>
#include <conio.h>
#include <string>
using namespace std;

char* loadLevel(string levelName, int width, int height);

int main() {

	int height;
	int width;
	char* level = loadLevel("Level.txt", width, height);
	int playerX = 0;
	int playerY = 0;


}

char* loadLevel(string levelName, int width, int height)
{
	levelName.insert(0, "../");
	ofstream levelFile;
	levelFile.open(levelName);

	if (!levelFile)
	{
		cout << "Error";
	}

	else
	{
		constexpr int tempSize = 25;
		char temp[tempSize];

		levelFile.getline(temp, tempSize, "\n");
		width = atoi(temp);

		levelFile.getline(temp, tempSize, "\n");
		height = atoi(temp);

		char* levelData = new char[width * height];
		levelData.read(levelData, width * height);
		return levelData;
	}


}