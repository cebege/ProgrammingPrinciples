#include <iostream>
#include <conio.h>

using namespace std;

constexpr char kCursor = '_';

constexpr char TopRightBorder = 187;
constexpr char TopLeftBorder = 201;
constexpr char BottomRightBorder = 188;
constexpr char BottomLeftBorder = 200;
constexpr char HoriztonalBorder = 205;
constexpr char VerticalBorder = 186;

constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;
constexpr int kEscape = 27;

void getDimensions(int& levelWidth, int& levelHeight);

void drawLevel(char* pLevel, int levelWidth, int levelHeight, int playerX, int playerY);
void drawTopBorder(int width); // REMEMBER
void drawBottomBorder(int width);
void drawLeftBorder();
void drawRightBorder();

bool editLevel(char* pLevel, int& playerX, int& playerY, int levelWidth, int levelHeight);

int getIndex(int x, int y, int width);

int main() {

	int levelWidth;
	int levelHeight;
	getDimensions(levelWidth, levelHeight);
	char* pLevel = new char[levelWidth * levelHeight];
	for (int i = 0; i < levelWidth * levelHeight; ++i)
	{
		pLevel[i] = ' ';
	}

	int cursorX = 0;
	int cursorY = 0;
	bool doneEditing = false;

	while (!doneEditing)
	{
		system("cls");
		drawLevel(pLevel, levelWidth, levelHeight, cursorX, cursorY);
		doneEditing = editLevel(pLevel, cursorX, cursorY, levelWidth, levelHeight);
	}
	system("cls");
	drawLevel(pLevel, levelWidth, levelHeight, -1, -1);
	delete pLevel;
	pLevel = nullptr;
}

void getDimensions(int& levelWidth, int& levelHeight)
{
	cout << "Enter width: ";
	cin >> levelWidth;
	cout << "Enter height: ";
	cin >> levelHeight;
}

void drawLevel(char* pLevel, int levelWidth, int levelHeight, int cursorX, int cursorY)
{
	drawTopBorder(levelWidth);
	for (int y = 0; y < levelHeight; ++y)
	{
		drawLeftBorder();
		for (int x = 0; x < levelWidth; ++x)
		{
			int index = getIndex(x, y, levelWidth);
				if ( x == cursorX && y == cursorY)
				{
					cout << kCursor;
				}
				else
				{
					int index = getIndex(x, y, levelWidth);
					cout << pLevel[index];
				}
			
		}
		drawRightBorder();
	}
	drawBottomBorder(levelWidth);
}

int getIndex(int x, int y, int width)
{
	return x + y * width;
}

void drawTopBorder(int width)
{
	cout << TopLeftBorder;
	for (int x = 0; x < width; ++x)
	{
		cout << HoriztonalBorder;
	}
	cout << TopRightBorder << endl;
}

void drawBottomBorder(int width)
{
	cout << BottomLeftBorder;
	for (int x = 0; x < width; ++x)
	{
		cout << HoriztonalBorder;
	}
	cout << BottomRightBorder << endl;
}

void drawLeftBorder()
{
	cout << VerticalBorder;
}

void drawRightBorder()
{
	cout << VerticalBorder << endl;
}

bool editLevel(char* pLevel, int& cursorX, int& cursorY, int levelWidth, int levelHeight)
{
	int input = _getch();
	int updatedCursorX = cursorX;
	int updatedCursorY = cursorY;

	if (input == kArrowInput)
	{
		int ArrowInput = _getch();

		switch (ArrowInput)
		{
		case kLeftArrow:
			updatedCursorX--;
			break;
		case kRightArrow:
			updatedCursorX++;
			break;
		case kUpArrow:
			updatedCursorY--;
			break;
		case kDownArrow:
			updatedCursorY++;
			break;
		}

		if (updatedCursorX < 0)
		{
			updatedCursorX = 0;
		}
		if (updatedCursorX == levelWidth)
		{
			updatedCursorX = levelWidth -1;
		}
		if (updatedCursorY < 0)
		{
			updatedCursorY = 0;
		}
		if (updatedCursorY == levelWidth)
		{
			updatedCursorY = levelWidth - 1;
		}

		cursorX = updatedCursorX;
		cursorY = updatedCursorY;
	}
	else
	{
		if (input == kEscape)
		{
			return true;
		}
		else
		{
			int index = getIndex(updatedCursorX, updatedCursorY, levelWidth);
			pLevel[index] = (char)input;
		}
	}
	return false;
}