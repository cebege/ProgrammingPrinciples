#include <iostream>
#include <string>
#include <fStream>
#include <Windows.h>


using namespace std;

void saveLevel(char* level, int width, int height);

int main() {



}

void saveLevel(char* level, int width, int height)
{
	cout << "level name: ";
	string levelName;
	cin >> levelName;

	levelName.insert(0, "../");
	ofstream levelFile;
	levelFile.open(levelName);

	if (!levelFile)
	{
		cout << "Error";
	}
	else
	{
		levelFile << height << endl;
		levelFile << width << endl;
		levelFile.write(level, height * width);
		if (!levelFile)
		{
			cout << "Error" << endl;
		}
		else
		{
			levelFile.close();
		}

	}
}