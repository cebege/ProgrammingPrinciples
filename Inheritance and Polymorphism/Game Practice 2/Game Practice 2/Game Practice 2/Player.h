#pragma once
#include "Key.h"

#include "PlaceableActor.h"

class Key;

class Player : public PlaceableActor
{
public:
	Player();

	bool hasKey();
	bool hasKey(int colour);
	void useKey();
	void dropKey();
	void pickUpKey(Key* Key);

	int addMoney(int money) { return mMoney += money; }
	int getMoney() { return mMoney; }

	int getLives() { return mLives; }
	void decrementLives() { mLives--; }

	virtual void draw() override;

private:
	Key* pCurrentKey;
	int mMoney;
	int mLives;

};