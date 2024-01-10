#include "Enemy.h"
#include <Windows.h>
#include <iostream>
using namespace std;

Enemy::Enemy(int x, int y, int deltaX, int deltaY)
	: PlaceableActor(x, y)
	, mMovementX(deltaX)
	, mMovementY(deltaY)
	, mCurrentMovementX(0)
	, mCurrentMovementY(0)
	, mDirectionX(0)
	, mDirectionY(0)
{
	if (mMovementX != 0)
	{
		mMovementX = 1;
	}
	if (mMovementY != 0)
	{
		mMovementY = 1;
	}
}

void Enemy::draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, kRedColour);
	cout << (char)153;
	SetConsoleTextAttribute(console, kRegularColour);
}

void Enemy::update()
{
	if (mMovementX != 0)
	{
		updateDirection(mMovementX, mCurrentMovementX, mDirectionX);
	}
	if (mMovementY != 0)
	{
		updateDirection(mMovementY, mCurrentMovementY, mDirectionY);
	}
}

void Enemy::updateDirection(int movement, int current, int direction)
{
	current += direction;

	if (abs(current) > movement)
	{
		current = movement * direction;
		direction *= -1;
	}
}