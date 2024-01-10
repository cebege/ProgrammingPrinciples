#include <iostream>
using namespace std;

class Point
{

public:

	int x;
	int y;

	Point(int x = 0, int y = 0)
		: x(x)
		, y(y)
	{};

	Point operator+ (const Point& other)
	{
		return Point(x + other.x, y + other.y);
	}

	friend ostream& operator << (ostream& left, const Point& right)
	{
		left << "(" << right.x << ", " << right.y << ")";
		return left;
	}

	Point operator+ (const Point& other)
	{
		return Point(x + other.x, y + other.y);
	}

	friend ofstream& operator << (ofstream& left, const Point& right)
	{
	}

	// p1 = -p2
	Point operator-() const
	{
		return Point(-x, -y);
	}

	// p1 * 5; Point multiply scalar.
	Point operator* (int s) const
	{
		return Point(x * s, y * s);
	}


	Point operator+ (const Point& other)
	{
		return Point (x + other.x, y + other.y)
	}

	Point operator* (int s)
	{
		return Point(x * s, y * s);
	}

	Point operator-()


};

int main() {

	Point p1(20, 50);
	Point p2(40, 20);
	Point p3(15, 10);

	Point p4 = p1 + p2;

	cout << p4;

}