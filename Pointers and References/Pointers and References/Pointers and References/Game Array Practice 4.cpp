#include <iostream>
#include <conio.h>
using namespace std;

constexpr char kPlayer = '@';

void draw_level(char my_level[], int width, int height, int player_x, int player_y);

int get_index(int x, int y, int width);

bool move_player(char my_level[], int& player_x, int& player_y, int width, bool& has_key);

int main() {

	const int width = 13;
	const int height = 11;

	char my_level[]{

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
		draw_level(my_level, width, height, player_x, player_y);
		game_over = move_player(my_level, player_x, player_y, width, has_key);
	}
	draw_level(my_level, width, height, player_x, player_y);
	cout << "You win!";

}

void draw_level(char my_level[], int width, int height, int player_x, int player_y)
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (player_x == x && player_y == y)
			{
				cout << kPlayer;
			}
			else
			{
				int index = get_index(x, y, width);
				cout << my_level[index];
			}
		}
		cout << endl;
	}
}

int get_index(int x, int y, int width)
{
	return x + y * width;
}

bool move_player(char my_level[], int& player_x, int& player_y, int width, bool& has_key)
{
	char input = _getch();
	int move_player_x = player_x;
	int move_player_y = player_y;

	switch (input)
	{
	case 'w':
	case 'W':
	{
		move_player_y--;
		break;
	}
	case 's':
	case 'S':
	{
		move_player_y++;
		break;
	}
	case 'd':
	case 'D':
	{
		move_player_x++;
		break;
	}
	case 'a':
	case 'A':
	{
		move_player_x--;
		break;
	}
	}

	int index = get_index(move_player_x, move_player_y, width);

	if (my_level[index] == ' ')
	{
		player_x = move_player_x;
		player_y = move_player_y;
	}
	if (my_level[index] == '*')
	{
		has_key = true;
		player_x = move_player_x;
		player_y = move_player_y;
		my_level[index] == ' ';
	}
	if (my_level[index] == 'D' && has_key)
	{
		my_level[index] == ' ';
		player_x = move_player_x;
		player_y = move_player_y;
	}
	if (my_level[index] == 'X')
	{
		my_level[index] == ' ';
		player_x = move_player_x;
		player_y = move_player_y;
		return true;
	}
	return false;
}
