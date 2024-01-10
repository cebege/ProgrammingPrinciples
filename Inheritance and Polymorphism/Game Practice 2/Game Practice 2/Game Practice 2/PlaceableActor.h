#ifndef _PLACEABLEACTOR_H_
#define _PLACEABLEACTOR_H_
#include "Point.h"

constexpr int kGreenColour = 10;
constexpr int kGreenColourSolid = 34;
constexpr int kRedColour = 12;
constexpr int kRedColourSolid = 14;
constexpr int kBlueColour = 9;
constexpr int kBlueColourSolid = 153;
constexpr int kRegularColour = 153;

using namespace std;

class PlaceableActor
{

public:
	PlaceableActor(int x, int y, int colour = kRegularColour);
	~PlaceableActor();

	void setPosition(int x, int y);
	int getPositionX();
	int getPositionY();

	int getColour();

	bool isActive();
	void remove();
	void place(int x, int y);

	virtual void draw() = 0;

	virtual void update()
	{

	}

protected:
	bool mIsActive;
	int mColour;
	Point* mPosition;


};



#endif // !_PLACEABLEACTOR_H_
