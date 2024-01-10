#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fStream>

using namespace std;

constexpr char Cursor = '_';

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

void GetDimensions(int& LevelHeight, int& LevelWidth);

void DisplayLevel(char* pLevel, int LevelHeight, int LevelWidth, int CursorX, int CursorY);

int GetIndex(int x, int y, int width);

void DisplayTopBorder(int width);
void DisplayBottomBorder(int width);
void DisplayLeftBorder();
void DisplayRightBorder();

bool EditLevel(char* pLevel, int& CursorX, int& CursorY, int width, int height);

void SaveLevel(char* pLevel, int width, int height);

int main()
{
	int LevelHeight;
	int LevelWidth;
	GetDimensions(LevelHeight, LevelWidth);
	
	char* pLevel = new char[LevelHeight * LevelWidth];

	for (int i = 0; i < LevelHeight * LevelWidth; ++i)
	{
		pLevel[i] = ' ';
	}

	int CursorX = 0;
	int CursorY = 0;
	bool DoneEditing = false;
	while (!DoneEditing)
	{
		system("cls");
		DisplayLevel(pLevel, LevelHeight, LevelWidth,CursorX, CursorY);
		DoneEditing = EditLevel(pLevel, CursorX, CursorY, LevelWidth, LevelHeight);

	}
	system("cls");
	DisplayLevel(pLevel, LevelHeight, LevelWidth, -1, -1);

	SaveLevel(pLevel, LevelWidth, LevelHeight);
	delete pLevel;
	pLevel = nullptr;
}

void GetDimensions(int& LevelHeight, int& LevelWidth)
{
	cout << "Level Width: ";
	cin >> LevelWidth;
	cout << "Level Height: ";
	cin >> LevelHeight;
}

void DisplayLevel(char* pLevel, int LevelHeight, int LevelWidth, int CursorX, int CursorY)
{
	DisplayTopBorder(LevelWidth);

	for (int y = 0; y < LevelHeight; ++y)
	{
		DisplayLeftBorder();
		for (int x = 0; x < LevelWidth; ++x)
		{
			if (CursorX == x && CursorY == y)
			{
				cout << Cursor;
			}
			else
			{
				int index = GetIndex(x, y, LevelWidth);
				cout << pLevel[index];
			}
		}
		DisplayRightBorder();
	}
	DisplayBottomBorder(LevelWidth);
}

int GetIndex(int x, int y, int width)
{
	return x + y * width;
}

void DisplayTopBorder(int width)
{
	cout << TopLeftBorder;
	for (int i = 0; i < width; ++i)
	{
		cout << HoriztonalBorder;
	}
	cout << TopRightBorder << endl;
}
void DisplayBottomBorder(int width)
{
	cout << BottomLeftBorder;
	for (int i = 0; i < width; ++i)
	{
		cout << HoriztonalBorder;
	}
	cout << BottomRightBorder << endl;
}
void DisplayLeftBorder()
{
	cout << VerticalBorder;
}
void DisplayRightBorder()
{
	cout << VerticalBorder << endl;
}

bool EditLevel(char* pLevel, int& CursorX, int& CursorY, int width, int height)
{
	int NewCursorX = CursorX;
	int NewCursorY = CursorY;
	int IntInput = _getch();

	if (IntInput == kArrowInput)
	{
		int ArrowInput = _getch();

		switch (ArrowInput)
		{
		case kLeftArrow:
			NewCursorX--;
			break;
		case kRightArrow:
			NewCursorX++;
			break;
		case kUpArrow:
			NewCursorY--;
			break;
		case kDownArrow:
			NewCursorY++;
			break;
		}

		if (NewCursorX < 0)
		{
			NewCursorX = 0;
		}
		if (NewCursorX == width)
		{
			NewCursorX = width -1;
		}
		if (NewCursorY < 0)
		{
			NewCursorY = 0;
		}
		if (NewCursorY == width)
		{
			NewCursorY = width -1;
		}

		CursorX = NewCursorX;
		CursorY = NewCursorY;
	}
	else
	{
		if (IntInput == kEscape)
		{
			return true;
		}
		else
		{
			int index = GetIndex(NewCursorX, NewCursorY, width); // Entering characters 
			pLevel[index] = (char)IntInput; 
		}
	}
	return false;
}

void SaveLevel(char* pLevel, int width, int height)
{
	cout << "What name do you want to save this file as? "; // 1) Ask user for level name
	string levelName;
	cin >> levelName;

	levelName.insert(0, "../"); // 2) WINDOWS GOING UP ONE LEVEL

	ofstream levelFile; // 3) ofstream levelFile and open
	levelFile.open(levelName);
	if (!levelFile)
	{
		cout << "Opening file failed." << endl;
	}
	else // 4) take in width and height and write the level file parameters
	{
		levelFile << width << endl;
		levelFile << height << endl;
		levelFile.write(pLevel, width * height);
		if (!levelFile)
		{
			cout << "Write Failed! " << endl;
		}
		levelFile.close(); // 5) close the level file
	}
}