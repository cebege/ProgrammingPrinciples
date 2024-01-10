#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>

using namespace std;

constexpr char kCursor = '_';

constexpr char topRightBorder = 187;
constexpr char topLeftBorder = 201;
constexpr char bottomRightBorder = 188;
constexpr char bottomLeftBorder = 200;
constexpr char horiztonalBorder = 205;
constexpr char verticalBorder = 186;

constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;
constexpr int kEscape = 27;

void getDimensions(int& width, int& height);

void drawLevel(char* pLevel, int width, int height, int playerX, int playerY);

bool updateLevel(char* pLevel, int width, int height, int& playerX, int& playerY);

void drawTopBorder(int width);
void drawBottomBorder(int width);
void drawLeftBorder();
void drawRightBorder();

void saveLevel(char* pLevel, int width, int height);

int getIndex(int x, int y, int width);

int main() {

	int width;
	int height;
	getDimensions(width, height);

	char* pLevel = new char[width * height];
	for (int i = 0; i < width * height; ++i)
	{
		pLevel[i] = ' ';
	}

	int cursorX = 0;
	int cursorY = 0;
	bool doneEditing = false;

	while (!doneEditing)
	{
		system("cls");
		drawLevel(pLevel, width, height, cursorX, cursorY);
		doneEditing = updateLevel(pLevel, width, height, cursorX, cursorY);
	}
	system("cls");
	drawLevel(pLevel, width, height, -1, -1);
	saveLevel(pLevel, width, height);
	delete[] pLevel;
	pLevel = nullptr;
}

void getDimensions(int& width, int& height)
{
	cout << "Width: ";
	cin >> width;
	cout << "Height: ";
	cin >> height;
}

void drawLevel(char* pLevel, int width, int height, int cursorX, int cursorY)
{
	drawTopBorder(width);
	for (int y = 0; y < height; ++y)
	{
		drawLeftBorder();
		for (int x = 0; x < width; ++x)
		{
			if (cursorX == x && cursorY == y)
			{
				cout << kCursor;
			}
			else
			{
				int index = getIndex(x, y, width);
				cout << pLevel[index];
			}
		}
		drawRightBorder();
	}
	drawBottomBorder(width);
}

bool updateLevel(char* pLevel, int width, int height, int& cursorX, int& cursorY)
{
	int input = _getch();
	int newCursorX = cursorX;
	int newCursorY = cursorY;

	if (input == kArrowInput)
	{
		int ArrowInput = _getch();

		switch (ArrowInput)
		{
		case kUpArrow:
			newCursorY--;
			break;
		case kDownArrow:
			newCursorY++;
			break;
		case kRightArrow:
			newCursorX++;
			break;
		case kLeftArrow:
			newCursorX--;
			break;
		}

		if (newCursorX < 0)
			newCursorX = 0;
		if (newCursorX == width)
			newCursorX = width - 1;
		if (newCursorY < 0)
			newCursorY = 0;
		if (newCursorY == width)
			newCursorY = width - 1;

		cursorX = newCursorX;
		cursorY = newCursorY;
		return false;
	}
	if (input == kEscape)
	{
		return true;
	}
	else
	{
		int index = getIndex(newCursorX, newCursorY, width);
		pLevel[index] = (char)input;
	}
	return false;
}

void drawTopBorder(int width)
{
	cout << topLeftBorder;
	for (int i = 0; i < width; ++i)
	{
		cout << horiztonalBorder;
	}
	cout << topRightBorder << endl;
}

void drawBottomBorder(int width)
{
	cout << bottomLeftBorder;
	for (int i = 0; i < width; ++i)
	{
		cout << horiztonalBorder;
	}
	cout << bottomRightBorder << endl;
}

void drawLeftBorder()
{
	cout << verticalBorder;
}

void drawRightBorder()
{
	cout << verticalBorder << endl;
}

int getIndex(int x, int y, int width)
{
	return x + y * width;
}

void saveLevel(char * pLevel, int width, int height)
{
	cout << "Level save name: ";
	string levelName;
	cin >> levelName;

	levelName.insert(0, "../");
	ofstream levelFile;
	levelFile.open(levelName);

	if (!levelFile)
	{
		cout << "Opening file failed.";
	}
	else
	{
		levelFile << width << endl;
		levelFile << height << endl;
		levelFile.write(pLevel, width * height);

		if (!levelFile)
		{
			cout << "Write Failed!";
		}
		else
		{
			levelFile.close();
		}
	}
}