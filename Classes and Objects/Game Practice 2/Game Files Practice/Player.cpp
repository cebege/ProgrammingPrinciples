#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
	: hasKey(false) {};

Player::~Player() {};

void Player::setXYPosition(int x, int y)
{
	playerPosition.x = x;
	playerPosition.y = y;
}

void Player::drawPlayer()
{
	cout << kPlayer;
}