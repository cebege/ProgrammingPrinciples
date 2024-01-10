#include "Player.h"
#include "Key.h"
using namespace std;

constexpr int kStandardLives = 2;

Player::Player()
	: PlaceableActor(0, 0)
	, mCurrentKey(false)
	, mLives(kStandardLives)
	, mMoney(0)
{};

bool Player::hasKey()
{
	return mCurrentKey != nullptr;
}

bool Player::hasKey(int colour)
{
	return hasKey() && mCurrentKey->getColour() == colour;
}

void Player::useKey()
{
	mCurrentKey->remove();
	mCurrentKey = nullptr;
}

void Player::dropKey()
{
	mCurrentKey->place(getXPosition(), getYPosition());
}

void Player::pickUpKey(Key* key)
{
	mCurrentKey = key;
}

void Player::draw()
{
	cout << "@";
}