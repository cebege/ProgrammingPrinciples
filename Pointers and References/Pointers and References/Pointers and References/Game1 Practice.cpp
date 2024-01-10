#include <iostream>

using namespace std;

void display_map(char map[], int width, int height);

int get_index(int x, int y, int width);

int main() {

	const int kwidth = 6;
	const int kheight = 5;

	char map[] = {
				'+', '-', '-', '-', '-', '+',
				'|', ' ', '@', ' ', ' ', '|',
				'|', ' ', ' ', ' ', ' ', '|',
				'|', ' ', ' ', ' ', 'X', '|',
				'+', '-', '-', '-', '-', '+',
	};

	display_map(map, kwidth, kheight);

}

void display_map(char map[], int width, int height)
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int index = get_index(x, y, width);
			cout << map[index];
		}
		cout << endl;
	}
}

int get_index(int x, int y, int width)
{
	return x + y * width;
}