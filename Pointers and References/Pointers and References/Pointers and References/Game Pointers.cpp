#include <iostream>
#include <conio.h>

using namespace std;
constexpr char kPlayer = '@';

int get_index(int x, int y, int width);
void draw_level(char level_array[], int width, int height, int playerX, int playerY);
bool update_player(char level[], int& playerX, int& playerY, int width, bool& player_has_key);

int main() {

	const int kwidth = 13;
	const int kheight = 11;

	char level_array[] = {
				'+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+',
				'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '*', ' ', '|',
				'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|',
				'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|',
				'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ', '|',
				'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
				'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|',
				'|', ' ', ' ', ' ', ' ', '-', '-', '-', '-', '-', '-', ' ', '|',
				'|', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', '|',
				'|', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', 'X', ' ', '|',
				'+', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '+',
	};
	int playerX = 1;
	int playerY = 1;
	bool player_has_key = false;
	bool game_over = false;
	while (!game_over)
	{
		system("cls");
		draw_level(level_array, kwidth, kheight, playerX, playerY);
		game_over = update_player(level_array, playerX, playerY, kwidth, player_has_key);
	}

	draw_level(level_array, kwidth, kheight, playerX, playerY);
	cout << "You Won!" << endl;

	draw_level(level_array, kwidth, kheight, playerX, playerY);
}

int get_index(int x, int y, int width)
{
	return x + y * width;
}

void draw_level(char level_array[], int width, int height, int playerX, int playerY)
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
				cout << level_array[index];
			}
		}
		cout << endl;
	}

}

bool update_player(char level[], int& playerX, int& playerY, int width, bool& player_has_key)
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
	if (level[index] == '*')
	{
		player_has_key = true;
		level[index] = ' '; // erase key from map
		playerX = new_player_x;
		playerY = new_player_y;
	}
	if (level[index] == 'D' && player_has_key)
	{
		player_has_key = false;
		level[index] = ' '; // erase door from map
		playerX = new_player_x;
		playerY = new_player_y;
	}
	if (level[index] == 'X')
	{
		level[index] = ' ';
		playerX = new_player_x;
		playerY = new_player_y;
		return true;
	}
	return false;
}