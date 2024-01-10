#include "Enemy.h"
#include <Windows.h>
#include <iostream>

Enemy::Enemy(int x, int y, int deltaX, int deltaY)
	: PlaceableActor(x, y)
	, _currentMovementX(0)
	, _currentMovementY(0)
	, _directionX(0)
	, _directionY(0)
	, _movementX(deltaX)
	, _movementY(deltaY)
{
	if (_movementX != 0)
	{
		_movementX = 1;
	}
	if (_movementY != 0)
	{
		_movementY = 1;
	}
}

void Enemy::update()
{
	if (_movementX != 0)
	{
		updateDirection(_currentMovementX, _movementX, _directionX);
	}
	if (_movementY != 0)
	{
		updateDirection(_currentMovementY, _movementY, _directionY);
	}
}

void Enemy::updateDirection(int current, int movement, int direction)
{
	current += direction;

	if (abs(current > movement))
	{
		current = movement * direction;
		current *= -1;
	}
}

ActorType Enemy::getType()
{
	return ActorType::Enemy;
}

void Enemy::draw()
{
	cout << char(153);
}