#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
using namespace std;

void getDimensions(int & width, int & height);

void displayLevel(char* level, int width, int height, int cursorX, int cursorY);

bool updateLevel(char* level, int width, int height, int& cursorX, int& cursorY);

int getIndex(int x, int y, int width);

void saveLevel(char* level, int width, int height);

int main() {

	int width;
	int height;
	getDimensions(width, height);
	char* level = new char[width * height];
	for (int i = 0; i < width * height; ++i)
		cout << level[i];

	int cursorX = 1;
	int cursorY = 1;
	bool doneEditing = false;

	while (!doneEditing)
	{
		system("cls");
		displayLevel(level, width, height, cursorX, cursorY);
		doneEditing = updateLevel(level, width, height, cursorX, cursorY)
	}

	saveLevel(level, width, height);

	delete[] level;
	level = nullptr;
}

void getDimensions(int & width, int & height)
{
	cout << "Enter width: ";
	cin >> width;
	cout << "Enter height: ";
	cin >> height;
}

void displayLevel(char* level, int width, int height, int cursorX, int cursorY)
{
	DrawTopBorder();
	for (int y = 0; y < height; ++y)
	{
		DrawLeftBorder();
		for (int x = 0; x < width; ++x)
		{
			if (cursorX == x && cursorY == y)
			{
				cout << kCursor;
			}
			else
			{
				int Index = getIndex(x, y, width);
				cout << level[Index];
			}
		}
		DrawRightBorder();
	}
	DrawBottomBorder();
}

int getIndex(int x, int y, int width)
{
	return x + y * width;
}

bool updateLevel(char* level, int width, int height, int& cursorX, int& cursorY)
{
	int Input = _getch();
	int updatedCursorX = cursorX;
	int updatedCursorY = cursorY;

	if (Input == kArrowInt)
	{
		int ArrowInput = _getch();

		switch (ArrowInput)
		{
		case kUpArrow:
			updatedCursorY--;
			break;
		case kDownArrow:
			updatedCursorY++;
			break;
		case kRightArrow:
			updatedCursorX++;
			break;
		case kLeftArrow:
			updatedCursorX--;
			break;
		}

		if (updatedCursorX < 0)
			updatedCursorX = 0;
		if (updatedCursorX == width)
			updatedCursorX = width - 1;
		if (updatedCursorY < 0)
			updatedCursorY = 0;
		if (updatedCursorY == width)
			updatedCursorY = width - 1;

		cursorX = updatedCursorX;
		cursorY = updatedCursorY;
	}
	if (Input == kEscape)
	{
		return true;
	}
	else
	{
		int Index = getIndex(updatedCursorX, updatedCursorY, width);
		level[Index] = (char)Index;
	}
	return false;
}

void saveLevel(char* level, int width, int height)
{
	cout << "file Save name";
	string levelName;
	cin >> levelName;

	levelName.insert(0,"../");
	ofstream levelFile;
	levelFile.open(levelName);

	if (!levelFile)
	{
		cout << "Error";
	}
	else
	{
		levelFile << width << endl;
		levelFile << height << endl;
		levelFile.write(level, width * height);
		if (levelFile)
		{
			cout << "Error";
		}
		else
		{
			levelFile.close();
		}
	}
}
