#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "PlaceableActor.h"

class Key; // you can only forward declare pointer types, specific items

class Player : public PlaceableActor
{

public:
	Player();

	bool HasKey(); // Confusing
	bool HasKey(int colour);
	void PickUpKey(Key* key);
	void UseKey();
	void DropKey();

	// nothing in the class is using key in a functions

	void AddMoney(int money) { m_money += money; }
	int GetMoney() { return m_money; }

	int GetLive() { return m_lives; }
	void DecrementLives() { m_lives--; }

	virtual void Draw() override;

private:
	Key* m_pCurrentKey;
	int m_money;
	int m_lives;

};

#endif // !_PLAYER_H_
