#pragma once
#include "PlaceableActor.h"

class Enemy : public PlaceableActor
{
public:

	Enemy(int x, int y, int deltaX, int deltaY);

	virtual void draw() override;
	virtual void update() override;

private:

	int mMovementX;
	int mMovementY;

	int mCurrentMovementX;
	int mCurrentMovementY;

	int mDirectionX;
	int mDirectionY;

	void updateDirection(int& movement, int& current, int& direction);

};