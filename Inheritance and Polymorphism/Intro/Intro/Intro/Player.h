#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Character.h"

class Player : public Character
{
public:
	void speak() override
	{
		cout << "I am a Player." << endl;
	}
};

#endif