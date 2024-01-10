#include "Player.h"
#include <iostream>
#include <Windows.h>
using namespace std;

constexpr char kPlayer = '@';

Player::Player(bool hasKey)
	: hasKey{ hasKey } {};

Player::~Player()
{};

void Player::setXYposition(int x, int y)
{
	playerPosition.x = x;
	playerPosition.y = y;
}

void Player::drawPlayer()
{
	cout << kPlayer;
}





