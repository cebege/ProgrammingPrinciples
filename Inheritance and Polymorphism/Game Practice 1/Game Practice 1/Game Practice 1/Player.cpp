#include "Player.h"
#include "Key.h"
#include <iostream>
using namespace std;

constexpr int standardLives = 3;

Player::Player()
	: PlaceableActor(0, 0),
	mLives(standardLives),
	mMoney(0),
	mCurrentKey(nullptr)
{};

bool Player::hasKey()
{
	return mCurrentKey != nullptr;
}

bool Player::hasKeyColour(int colour)
{
	return hasKey() && mCurrentKey->getColour() == colour;
}

void Player::dropKey()
{
	if (mCurrentKey)
	{
		mCurrentKey->placeKey();
		mCurrentKey = nullptr;
	}
}

void Player::useKey()
{
	mCurrentKey->removeKey();
	mCurrentKey = nullptr;
}

void Player::pickUpKey(Key* key)
{
	mCurrentKey = key;
}

void Player::draw()
{
	cout << @
}





