constexpr int kGreenColour = 10;
constexpr int kGreenColourSolid = 34;
constexpr int kRedColour = 12;
constexpr int kRedColourSolid = 14;
constexpr int kBlueColour = 9;
constexpr int kBlueColourSolid = 153;
constexpr int kRegularColour = 153;
#include "Point.h"

using namespace std;

class PlaceableActor
{
public:
	PlaceableActor(int x, int y, int colour = kRegularColour);
	~PlaceableActor();

	int getPositionX() { return mPosition->x; }
	int getPositionY() { return mPosition->y; }

	int* getPositionXPointer() { return &(mPosition->x); }
	int* getPositionYPointer() { return &(mPosition->y); }

	int getColour() { return mColour; }

	bool isActive() { mActive = true; }
	bool removeKey() { mActive = false; }
	bool returnActivity() { return mActive; }

	void setXYPosition(int x, int y);

	void placeKey(int x, int y);

	virtual void draw() = 0;
	virtual void Update()
	{

	};

protected:
	Point* mPosition;
	bool mActive;
	int mColour;

};
