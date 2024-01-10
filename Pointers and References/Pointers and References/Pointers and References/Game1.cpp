#include <iostream>

using namespace std;

void DisplayMap(char map[], int width, int height);

int get_index_from_xy(int x, int y, int width);


int main() {

	const int kheight = 5;
	const int kwidth = 6;

	char map[] = {
					'+', '-', '-', '-', '-', '+',
					'|', ' ', '@', ' ', ' ', '|', 
					'|', ' ', ' ', ' ', ' ', '|', 
					'|', ' ', ' ', ' ', 'X', '|', 
					'+', '-', '-', '-', '-', '+', 
	};

	DisplayMap(map, kwidth, kheight);

}

void DisplayMap(char map[], int width, int height)
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int index = get_index_from_xy(x, y, width);
			cout << map[index];
		}
		cout << endl;
	}
}

int get_index_from_xy(int x, int y, int width)
{
	return x + y * width;
}