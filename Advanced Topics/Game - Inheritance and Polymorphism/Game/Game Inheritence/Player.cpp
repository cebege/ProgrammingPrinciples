#include "Player.h"
#include "Key.h" // using key in a function
#include <iostream>

using namespace std;

constexpr int kStartNumberOfLives = 20;

Player::Player()
	: PlaceableActor(0,0)
	, m_pCurrentKey(nullptr)
	, m_money(0)
	, m_lives(kStartNumberOfLives)
{
};

bool Player::HasKey()
{
	return m_pCurrentKey != nullptr;
}

bool Player::HasKey(ActorColour colour)
{
	return HasKey() && m_pCurrentKey->GetColour() == colour;
}

void Player::PickUpKey(Key* key)
{
	m_pCurrentKey = key;
}

void Player::UseKey()
{
	m_pCurrentKey->Remove();
	m_pCurrentKey = nullptr;
}

void Player::DropKey()
{
	if (m_pCurrentKey)
	{
		m_pCurrentKey->Place(m_pPosition->x, m_pPosition->y);
		m_pCurrentKey = nullptr;
	}
}

void Player::Draw()
{
	cout << "@";
}