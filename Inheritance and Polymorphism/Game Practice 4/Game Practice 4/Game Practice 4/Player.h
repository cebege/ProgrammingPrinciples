#pragma once
#include "PlaceableActor.h"

class Key;

class Player : public PlaceableActor
{
private:
	Key* mCurrentKey;
	int mLives;
	int mMoney;

public:
	Player(int x, int y);
	~Player();
	
	bool hasKey();
	bool hasKeyColour(int colour);
	void useKey();
	void pickUpKey(Key* key);
	void dropKey();

	int getLives() { return mLives; }
	void decrementLives() { mLives--; }

	void addMoney(int money) { mMoney += money; }

	virtual void draw() override;
};