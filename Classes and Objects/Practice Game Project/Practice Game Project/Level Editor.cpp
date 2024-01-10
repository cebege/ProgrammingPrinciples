//Remeber to put the cout in the print level with a blank space.
// close the if loop in the edit level.
// Input not Index in the edit level
// EQUALS TO, not insert within the border condition.

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>

using namespace std;

constexpr char kCursor = '_';

void getDimensions(int& width, int& height);

int getIndex(int x, int y, int width);

void drawLevel(char* pLevel, int width, int height, int cursorX, int cursorY);
bool editLevel(char* pLevel, int width, int height, int& cursorX, int& cursorY);

void drawTopBorder(int width);
void drawBottomBorder(int width);
void drawLeftBorder();
void drawRightBorder();

void saveLevel(char* pLevel, int width, int height);

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

	int width;
	int height;
	getDimensions(width, height);
	char* pLevel = new char[width * height];
	for (int i = 0; i < width * height; ++i)
	{
		pLevel[i] = ' ';
	}

	int cursorX = 1;
	int cursorY = 1;
	bool doneEditing = false;

	while (!doneEditing)
	{
		system("cls");
		drawLevel(pLevel, width, height, cursorX, cursorY);
		editLevel(pLevel, width, height, cursorX, cursorY);
	}
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

	int updatedCursorX = cursorX;
	int updatedCursorY = cursorY;
	int Input = _getch();

	if (Input == kArrowInput)
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
		{
			updatedCursorX = 0;
		}
		if (updatedCursorX == width)
		{
			updatedCursorX = width - 1;
		}
		if (updatedCursorY < 0)
		{
			updatedCursorY = 0;
		}
		if (updatedCursorY == width)
		{
			updatedCursorY = width - 1;
		}

		cursorX = updatedCursorX;
		cursorY = updatedCursorY;
	}
	else {
		if (Input == kEscape)
		{
			return true;
		}
		else
		{
			int Index = getIndex(updatedCursorX, updatedCursorY, width);
			pLevel[Index] = (char)Input;
		}
	}
	return false;
}

int getIndex(int x, int y, int width)
{
	return x + y * width;
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

void drawLeftBorder()
{
	cout << VerticalBorder;
}

void drawRightBorder()
{
	cout << VerticalBorder << endl;
}

void saveLevel(char * pLevel, int width, int height)
{
	cout << "Name of Level Save: ";
	string levelName;
	cin >> levelName;

	levelName.insert(0, "../");
	ofstream levelFile;
	levelFile.open(levelName);

	if (!levelFile)
	{
		cout << "Error.";
	}
	else
	{
		levelFile << width << endl;
		levelFile << height << endl;
		levelFile.write(pLevel, width * height);
		if (!levelFile)
		{
			cout << "Error";
		}
		else
		{
			levelFile.close();
		}
	}
}