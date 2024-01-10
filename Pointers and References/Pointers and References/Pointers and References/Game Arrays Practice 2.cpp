#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;

char* loadLevel(string levelName, int width, int height, int cursorX, int cursorY);

int main() {

	int height;
	int width;
	char* level = new char[width * height];


}

char* loadLevel(string levelName, int width, int height, int cursorX, int cursorY)
{
	levelName.insert(0, "../");
	ofstream levelFile;
	levelFile.open(levelName);

	if (!levelFile)
	{
		cout << "Error";
		return nullptr;
	}

	else
	{
		const int tempSize = 25;
		int temp[tempSize];

		levelFile.getline(temp, tempSize, "\n");
		width = atoi(temp);

		levelFile.getline(temp, tempSize, "\n");
		length = atoi(temp);

		char* levelData = new char[width * length];
		levelFile.read(levelData, wdith * length);
		return levelData;

	}

}

