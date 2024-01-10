#include "Player.h"
#include <iostream>

constexpr char kPlayer = '@';

Player::Player()
	: hasKey( false ) 
{
};

Player::~Player() {};

void Player::SetXYPosition(int x, int y)
{
	playerPosition.x = x;
	playerPosition.y = y;
}

void Player::DrawPlayer()
{
	std::cout << kPlayer;
}
