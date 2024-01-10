#include "Player.h"
#include <iostream>
using namespace std;

constexpr int startNumberOfLives = 3;

Player::Player()
	: PlaceableActor(0, 0)
	, mMoney(0)
	, mLives(startNumberOfLives)
	, pCurrentKey(nullptr)
{};

bool Player::hasKey()
{
	return pCurrentKey != nullptr;
}

bool Player::hasKey(int colour)
{
	return hasKey() && pCurrentKey->getColour() == colour;
}

void Player::pickUpKey(Key* key)
{
	pCurrentKey = key;
}

void Player::useKey()
{
	pCurrentKey->remove();
	pCurrentKey = nullptr;
}

void Player::dropKey()
{
	if (pCurrentKey)
	{
		pCurrentKey->place(mPosition->x, mPosition->y);
		pCurrentKey = nullptr;
	}
}

void Player::draw()
{
	cout << "@";
}