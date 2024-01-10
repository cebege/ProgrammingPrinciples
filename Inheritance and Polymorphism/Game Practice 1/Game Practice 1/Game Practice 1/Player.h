#include "PlaceableActor.h"

class Key;

using namespace std;

class Player : public PlaceableActor
{
	Player();

	bool hasKey();
	bool hasKeyColour(int colour);
	void dropKey();
	void useKey();
	void pickUpKey(Key* key);

	void decrementLives();
	int getLives();

	void addMoney();
	int getMoney();

	virtual void draw() override;

private:
	int mLives;
	int mMoney;
	Key* mCurrentKey;
};