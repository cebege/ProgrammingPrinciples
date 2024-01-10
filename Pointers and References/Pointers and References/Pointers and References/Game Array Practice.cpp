#include <iostream>
#include <conio.h>
using namespace std;

const char k_player = '@';

int get_index(int x, int y, int width);
void draw_level(char level_array[], int width, int height, int player_x, int player_y);
bool update_player(char level_array[], int& player_x, int& player_y, int width, bool& has_key);

int main() {

	const int width = 13;
	const int height = 11;
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

	int player_x = 1;
	int player_y = 1;
	bool has_key = false;
	bool game_over = false;

	while (!game_over)
	{
		system("cls");
		draw_level(level_array, width, height, player_x, player_y);
		game_over = update_player(level_array, player_x, player_y, width, has_key);
	}
	draw_level(level_array, width, height, player_x, player_y);
	cout << "You win!" << endl;
}

void draw_level(char level_array[], int width, int height, int player_x, int player_y)
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (player_x == x && player_y == y)
			{
				cout << k_player;
			}
			else {
				int index = get_index(x, y, width);
				cout << level_array[index];
			}
		}
		cout << endl;
	}
}

int get_index(int x, int y, int width)
{
	return x + y * width;
}

bool update_player(char level_array[], int& player_x, int& player_y, int width, bool& has_key)
{
	char input = _getch();

	int new_player_x = player_x;
	int new_player_y = player_y;

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

	int index = get_index(new_player_x, new_player_y, width);
	if (level_array[index] == ' ')
	{
		player_x = new_player_x;
		player_y = new_player_y;
	}
	if (level_array[index] == '*')
	{
		has_key = true;
		level_array[index] = ' ';
		player_x = new_player_x;
		player_y = new_player_y;
	}
	if (level_array[index] == 'D' && has_key)
	{
		level_array[index] = ' ';
		player_x = new_player_x;
		player_y = new_player_y;
	}
	if (level_array[index] == 'X')
	{
		player_x = new_player_x;
		player_y = new_player_y;
		return true;
	}
	return false;
};