#include <iostream>

using namespace std;

int main() {
	bool is_player_alive{ true };
	bool is_health_pack_available{ true };
	int player_health = 100;

	if (is_player_alive == true)
	{
		player_health -= 20;
		if (player_health < 0)
		{
			is_player_alive = false;
			player_health = 0;
		}
	}
	else
	{
		if (is_health_pack_available == true)
		{
			player_health = 100;
			is_health_pack_available = false;
			is_player_alive = true;
		}
	}
}