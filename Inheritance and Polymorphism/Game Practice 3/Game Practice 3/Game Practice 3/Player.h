#pragma once
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
	void pickUpKey(Key* key);

	int getLives() { return mLives; }
	void decrementLives() { mLives--; }
	
	void addMoney(int money) { mMoney += money; }
	int	getWorth() { return mMoney; }

	virtual void draw() override;

private:
	Key* mCurrentKey;
	int mMoney;
	int mLives;

};