#include <iostream>
#include <conio.h>
using namespace std;

constexpr char kCursor = '_';

void getLevelDims(int& levelWidth, int& levelHeight);

int getIndex(int x, int y, int width);

void drawLevel(char* pLevel, int width, int height, int cursorX, int cursorY);

bool editLevel(char* pLevel, int width, int height, int& cursorX, int& cursorY);

void drawTopBorder(int width);
void drawBottomBorder(int width);
void drawLeftBorder();
void drawRightBorder();

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

int main() {

	int levelWidth;
	int levelHeight;
	getLevelDims(levelWidth, levelHeight);
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
		doneEditing = editLevel(pLevel, levelWidth, levelHeight, cursorX, cursorY);
	}
	system("cls");
	drawLevel(pLevel, levelWidth, levelHeight, -1, -1); // REMEMBER
	delete pLevel;
	pLevel = nullptr; // REMEMBER

}

void getLevelDims(int& levelWidth, int& levelHeight)
{
	cout << "Width: ";
	cin >> levelWidth;
	cout << "Height :";
	cin >> levelHeight;
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

int getIndex(int x, int y, int width)
{
	return x + y * width;
}

bool editLevel(char* pLevel, int width, int height, int& cursorX, int& cursorY)
{
	int intInput = _getch();
	int newCursorX = cursorX;
	int newCursorY = cursorY;
	if (intInput == kArrowInput)
	{
		int ArrowInput = _getch(); // REMEMBER

		switch (ArrowInput)
		{
		case kDownArrow:
			newCursorY++;
			break;
		case kUpArrow:
			newCursorY--;
			break;
		case kRightArrow:
			newCursorX++;
			break;
		case kLeftArrow:
			newCursorX--;
			break;
		}

		if (newCursorX < 0)
		{
			newCursorX = 0;
		}
		if (newCursorX == width)
		{
			newCursorX = width - 1;
		}
		if (newCursorY < 0)
		{
			newCursorY = 0;
		}
		if (newCursorY == width)
		{
			newCursorY = width - 1;
		}

		cursorX = newCursorX; // REMEMBER
		cursorY = newCursorY;
	}
	else
	{
		if (intInput == kEscape)
		{
			return true;
		}
		else
		{
			int index = getIndex(newCursorX, newCursorY, width);
			pLevel[index] = (char)intInput;
		}
	}
	return false;
}

void drawTopBorder(int width)
{
	cout << TopLeftBorder;
	for (int i = 0; i < width; ++i)
	{
		cout << HoriztonalBorder;
	}
	cout << TopRightBorder << endl;
}

void drawBottomBorder(int width)
{
	cout << BottomLeftBorder;
	for (int i = 0; i < width; ++i)
	{
		cout << HoriztonalBorder;
	}
	cout << BottomRightBorder << endl;
}

void drawRightBorder()
{
	cout << VerticalBorder << endl;
}

void drawLeftBorder()
{
	cout << VerticalBorder;
}