#include <iostream> // fine
#include <conio.h> // fine
using namespace std; // fine

constexpr char k_player = '@'; // fine

void draw_level(char my_array[], int width, int height, int playerx, int playery); // fine

int get_index(int x, int y, int width); // fine

bool update_player(char my_array[], int& playerx, int& playery, int width, bool& has_key); // fine

int main() {

	const int width = 13; // fine
	const int height = 11; // fine

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

	int playerx = 1; // fine
	int playery = 1; // fine
	bool has_key = false; // fine
	bool game_over = false; // fine

	while (!game_over) // fine
	{
		system("cls"); // fine
		draw_level(level_array, width, height, playerx, playery); // fine
		game_over = update_player(level_array, playerx, playery, width, has_key); // fine
	}
	draw_level(level_array, width, height, playerx, playery); // fine
	cout << "You win!"; // fine
}

void draw_level(char my_array[], int width, int height, int playerx, int playery) // fine
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (playerx == x && playery == y)
			{
				cout << k_player;
			}
			else
			{
				int index = get_index(x, y, width);
				cout << my_array[index];
			}
		}
		cout << endl;
	}
}

int get_index(int x, int y, int width)
{
	return x + y * width;
}

bool update_player(char my_array[], int& playerx, int& playery, int width, bool& has_key) // fine
{
	char input = _getch();
	int update_playerx = playerx;
	int update_playery = playery;

	switch (input)
	{
	case 'w':
	case 'W':
	{
		update_playery--;
		break;
	}
	case 's':
	case 'S':
	{
		update_playery++;
		break;
	}
	case 'a':
	case 'A':
	{
		update_playerx--;
		break;
	}
	case 'd':
	case 'D':
	{
		update_playerx++;
		break;
	}
	}

	int index = get_index(update_playerx, update_playery, width);

	if (my_array[index] == ' ')
	{
		playerx = update_playerx;
		playery = update_playery;
	}
	if (my_array[index] == '*')
	{
		has_key = true;
		my_array[index] = ' ';
		playerx = update_playerx;
		playery = update_playery;
	}
	if (my_array[index] == 'D' && has_key)
	{
		has_key = false;
		my_array[index] = ' ';
		playerx = update_playerx;
		playery = update_playery;
	}
	if (my_array[index] == 'X')
	{
		my_array[index] = ' ';
		playerx = update_playerx;
		playery = update_playery;
		return true;
	}
	return false;
}