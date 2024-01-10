#include "Player.h"
#include <iostream>

constexpr int kPlayerLives = 3;

Player::Player()
	: PlaceableActor(0, 0)
	, _playerLives(kPlayerLives)
	, _playerMoney(0)
{};

ActorType Player::getType()
{
	return ActorType::Player;
}

void Player::draw()
{
	cout << "@";
}

void Player::useKey()
{
	if (_pCurrentKey)
	{
		_pCurrentKey->remove();
		_pCurrentKey = nullptr;
	}
}

void Player::dropKey()
{
	_pCurrentKey->place(_pCurrentKey->getPositionX(), _pCurrentKey->getPositionY());
	_pCurrentKey = nullptr;
}