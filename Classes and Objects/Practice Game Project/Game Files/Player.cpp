#include "Player.h"
#include <iostream>
using namespace std;

constexpr char kPlayer = '@';

Player::Player() {};

Player::~Player() {};

void Player::setPlayerXYPosition(int x, int y)
{
	playerPosition.x = x;
	playerPosition.y = y;
}

bool Player::PickUpKey()
{
	hasKey = true;
}
bool Player::UseKey()
{
	hasKey = false;
}

void Player::drawPlayer()
{
	cout << kPlayer;
}
