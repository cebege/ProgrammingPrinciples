#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

void getDimensions(int & width, int & height);

void drawLevel(char* pLevel, int width, int height, int cursorX, int cursorY);
bool editLevel(char * pLevel, int width, int height, int& cursorX, int& cursorY);
void saveLevel(char* pLevel, int width, int height);

void drawTopBorder(int width);
void drawBottomBorder(int width);
void drawLeftBorder();
void drawRightBorder();

int getIndex(int x, int y, int width);

void drawTopBorder(int width);

constexpr char kCursor = '_';

constexpr char kTopRightBorder = 187;
constexpr char kTopLeftBorder = 201;
constexpr char kBottomRightBorder = 188;
constexpr char kBottomLeftBorder = 200;
constexpr char kHoriztonalBorder = 205;
constexpr char kVerticalBorder = 186;

constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;
constexpr int kEscape = 27;

int main() {

	int width;
	int height;
	getDimensions(width, height);

	char* pLevel = new char[width * height];
	for (int i = 0; i < width * height; ++i)
	{
		pLevel[i] = ' ';
		cout << pLevel[i];
	}

	int cursorX = 1;
	int cursorY = 1;
	bool doneEditing = false;

	while (!doneEditing)
	{
		system("cls");
		drawLevel(pLevel, width, height, cursorX, cursorY);
		doneEditing = editLevel(pLevel, width, height, cursorX, cursorY);
	}
	saveLevel(pLevel, width, height);
	delete[] pLevel;
	pLevel = nullptr;
}

void getDimensions(int& width, int& height)
{
	cout << "Width: ";
	cin >> width;
	cout << "Length: ";
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
				int Index = getIndex(x, y, width);
				cout << pLevel[Index];
			}
		}
		drawRightBorder();
	}
	drawBottomBorder(width);
}

bool editLevel(char* pLevel, int width, int height, int& cursorX, int& cursorY)
{
	int Input = _getch();
	int newCursorX = cursorX;
	int newCursorY = cursorY;

	if (Input == kArrowInput)
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
			newCursorX = width -1;
		if (newCursorY < 0)
			newCursorY = 0;
		if (newCursorY == width)
			newCursorY = width - 1;

		cursorX = newCursorX;
		cursorY = newCursorY;
		return false;
	}
	if (Input == kEscape)
	{
		return true;
	}
	else
	{
		int Index = getIndex(newCursorX, newCursorY, width);
		pLevel[Index] = (char)Input;
		return false;
	}
}

int getIndex(int x, int y, int width)
{
	return x + y * width;
}

void drawTopBorder(int width)
{
	cout << kTopLeftBorder;
	for (int i = 0; i < width; ++i)
	{
		cout << kHoriztonalBorder;
	}
	cout << kTopRightBorder << endl;
}

void drawBottomBorder(int width)
{
	cout << kBottomLeftBorder;
	for (int i = 0; i < width; ++i)
	{
		cout << kHoriztonalBorder;
	}
	cout << kBottomRightBorder << endl;
}

void drawLeftBorder()
{
	cout << kVerticalBorder;
}

void drawRightBorder()
{
	cout << kVerticalBorder << endl;
}

void saveLevel(char * pLevel, int width, int height)
{
	cout << "File save: ";
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
		levelFile << width << endl;
		levelFile << height << endl;
		levelFile.write(pLevel, width * height);

		if (!levelFile)
		{
			cout << "Error.";
		}
		else
		{
			levelFile.close();
		}
	}

}