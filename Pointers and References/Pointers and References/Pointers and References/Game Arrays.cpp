#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fStream>

using namespace std;
constexpr char kPlayer = '@';
constexpr char WAL = 219;
constexpr char KEY = 232;
constexpr char DOR = 179;
constexpr char GOL = 36;
constexpr int kOpenDoorColour = 10;
constexpr int kClosedDoorColour = 12;
constexpr int kRegularDoorColour = 7;

int get_index(int x, int y, int width);
void draw_level(char * level_array, int width, int height, int playerX, int playerY, bool player_has_key);
bool update_player(char * level, int& playerX, int& playerY, int width, bool& player_has_key);
void PlayDoorClose();
void PlayerDoorOpen();
void PickUpKey();
void Win();
char* LoadLevel(string levelName, int& width, int& height);
bool ConvertLevel(char* level, int width, int height, int& playerX, int& playerY);

int main() {

	int kwidth;
	int kheight;
	char* level_array = LoadLevel("Level1.txt", kwidth, kheight);
	int playerX = 1;
	int playerY = 1;
	bool anyWarnings = ConvertLevel(level_array, kwidth, kheight, playerX, playerY);
	if (anyWarnings)
	{
		cout << "There are some warnings in the level data. see above." << endl;
		system("pause");
	}
	bool player_has_key = false;
	bool game_over = false;
	while (!game_over)
	{
		system("cls");
		draw_level(level_array, kwidth, kheight, playerX, playerY, player_has_key);
		game_over = update_player(level_array, playerX, playerY, kwidth, player_has_key);
	}
  
	draw_level(level_array, kwidth, kheight, playerX, playerY, player_has_key);
	cout << "You Won!" << endl;
	Win();

	delete [] level_array;
	level_array = nullptr;
}

char* LoadLevel(string levelName, int& width, int& height)
{
	levelName.insert(0, "../");
	ifstream levelFile;
	levelFile.open(levelName);
	if (!levelFile)
	{
		cout << "An error has occured." << endl;
		return nullptr;
	}
	else
	{
		constexpr int tempSize = 25;
		char temp[tempSize];

		levelFile.getline(temp, tempSize, '\n');
		width = atoi(temp); // converts integer into width.

		levelFile.getline(temp, tempSize, '\n');
		height = atoi(temp);

		char* levelData = new char[width * height]; // array that we need to deallocate.
		levelFile.read(levelData, width * height);
		return levelData;
	}
}


bool ConvertLevel(char* level, int width, int height, int& playerX, int& playerY)
{
	bool anyWarnings = false;

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int intIndex = get_index(x, y, width);

			switch (level[intIndex])
			{
			case '+':
			case '-':
			case '|':
			{
				level[intIndex] = WAL;
				break;
			}
			case '*':
			{
				level[intIndex] = KEY;
				break;
			}
			case 'X':
			{
				level[intIndex] = GOL;
				break;
			}
			case 'D':
			{
				level[intIndex] = DOR;
				break;
			}
			case '@':
			{
				level[intIndex] = ' ';
				playerX = x;
				playerY = y;
				break;
			}
			case ' ':
				break;
			default:
			{
				cout << "Invalid character in file " << level[intIndex] << endl;
				anyWarnings = true;
				break;
			}
			}
		}
	}

	return anyWarnings;
}

	int get_index(int x, int y, int width)
	{
		return x + y * width;
	}

	void draw_level(char * level_array, int width, int height, int playerX, int playerY, bool player_has_key)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				if (playerX == x && playerY == y)
				{
					cout << kPlayer;
				}
				else
				{
					int index = get_index(x, y, width);
					HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
					if (level_array[index] == DOR)
					{
						if (player_has_key)
						{
							SetConsoleTextAttribute(console, kOpenDoorColour);
						}
						else
						{
							SetConsoleTextAttribute(console, kClosedDoorColour);
						}
					}
					else
					{
						SetConsoleTextAttribute(console, kRegularDoorColour);
					}
					cout << level_array[index];
				}
			}
			cout << endl;
		}

	}

	bool update_player(char * level, int& playerX, int& playerY, int width, bool& player_has_key)
	{
		char input = _getch(); // helps the player move without having to press enter every time.

		int new_player_x = playerX;
		int new_player_y = playerY;

		switch (input)
		{
		case 'w':
		case 'W':
		{
			new_player_y--;
			break;
		}
		case 's':
		case 'S':
		{
			new_player_y++;
			break;
		}
		case 'a':
		case 'A':
		{
			new_player_x--;
			break;
		}
		case 'd':
		case 'D':
		{
			new_player_x++;
			break;
		}
		default:
			break;
		}

		int index = get_index(new_player_x, new_player_y, width); // give us the index where the player wants to move.
		if (level[index] == ' ')
		{
			playerX = new_player_x;
			playerY = new_player_y;
		}
		if (level[index] == KEY)
		{
			player_has_key = true;
			level[index] = ' '; // erase key from map
			playerX = new_player_x;
			playerY = new_player_y;
			PickUpKey();
		}
		if (level[index] == DOR && player_has_key)
		{
			player_has_key = false;
			level[index] = ' '; // erase door from map
			playerX = new_player_x;
			playerY = new_player_y;
			PlayerDoorOpen();
		}
		if (level[index] == !player_has_key)
		{
			PlayDoorClose();
		}
		if (level[index] == GOL)
		{
			level[index] = ' ';
			playerX = new_player_x;
			playerY = new_player_y;
			return true;
		}
		return false;
	}

	void PlayDoorClose()
	{
		Beep(500, 75); // frequency and duration
		Beep(500, 75);
	}
	void PlayerDoorOpen()
	{
		Beep(1397, 97);
	}
	void PickUpKey()
	{
		Beep(1568, 100);
	}
	void Win()
	{
		Beep(1568, 200);
		Beep(1568, 200);
		Beep(1568, 200);
		Beep(1245, 1000);
		Beep(1397, 200);
		Beep(1397, 200);
		Beep(1397, 200);
		Beep(1175, 1000);

	}