#include "Player.h"
#include "Enemy.h"

int main() {
	Player player;
	Enemy enemy;

	player.speak();
	enemy.speak();

	constexpr int numberOfCharacters = 25;
	constexpr int numberOfPlayers = 2;
	constexpr int numberOfEnemies = numberOfCharacters - numberOfPlayers;

	Character* pCharacterArray[numberOfCharacters];

	for (int i = 0; i < numberOfPlayers; ++i)
	{
		pCharacterArray[i] = new Player();
	}

	for (int i = 0; i < numberOfEnemies; ++i)
	{
		pCharacterArray[i + numberOfPlayers] = new Enemy();
	}

	for (int i = 0; i < numberOfCharacters; ++i)
	{
		pCharacterArray[i]->speak();
	}

	for (int i = 0; i < numberOfCharacters; ++i)
	{
		delete[] pCharacterArray[i];
		pCharacterArray[i] = nullptr;
	}

}