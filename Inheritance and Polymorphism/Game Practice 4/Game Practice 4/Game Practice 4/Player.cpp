#include "Player.h"
#include "Key.h"

using namespace std;

constexpr int kStandardLives = 3;

Player::Player(int x, int y)
	: PlaceableActor(x, y)
	, mLives(kStandardLives)
	, mMoney(0)
{};

Player::~Player()
{
	if (mCurrentKey != nullptr)
	{
		delete mCurrentKey;
		mCurrentKey = nullptr;
	}
}

bool Player::hasKey()
{
	return mCurrentKey;
}

bool Player::hasKeyColour(int colour)
{
	return hasKey() && mCurrentKey->getColour() == colour;
}

void Player::useKey()
{
	mCurrentKey->remove();
}

void Player::pickUpKey(Key* key)
{
	mCurrentKey = key;
}

void Player::dropKey()
{
	if (mCurrentKey != nullptr)
	{
		mCurrentKey->remove();
		mCurrentKey->place(mPosition->x, mPosition->y);
	}
}