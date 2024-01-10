#include <iostream>

using namespace std;

const int kheight = 5;
const int kwidth = 6;

void display_map(char map [kheight][kwidth]);

int main() {

	char map[kheight][kwidth] = {

	{'+', '-', '-', '-', '-', '+',},
	{'|', ' ', '@', ' ', ' ', '|', },
	{'|', ' ', ' ', ' ', ' ', '|', },
	{'|', ' ', ' ', ' ', 'X', '|', },
	{'+', '-', '-', '-', '-', '+', },

	};

	display_map(map);

}

void display_map(char map[kheight][kwidth])
{
	for (int i{ 0 }; i < kheight; ++i)
	{
		for (int j{ 0 }; j < kwidth; ++j)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}