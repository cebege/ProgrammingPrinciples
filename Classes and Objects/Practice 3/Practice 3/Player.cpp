#include "Player.h"
#include <iostream>
using namespace std;

constexpr char player = '@';

Player::Player()
	: hasKey( false ) {};

Player::~Player()
{

}

void Player::setPlayerPosition(int x, int y)
{
	playerPosition.x = x;
	playerPosition.y = y;
}

void Player::drawPlayer()
{
	cout << player;
}
