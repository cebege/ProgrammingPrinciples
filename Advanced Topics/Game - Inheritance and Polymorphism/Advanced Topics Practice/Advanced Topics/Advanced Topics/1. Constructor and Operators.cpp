#include <iostream>
using namespace std;

class Point
{
public:
	int x;
	int y;

public:
	Point(int x = 0, int y = 0)
		: x(x)
		, y(y)
	{};

	//Point Add(const Point& other)
	//{
	//	return Point(x + other.x, y + other.y);
	//}

	//Point Subtract(const Point& other)
	//{
	//	return Point(x - other.x, y - other.y);
	//}

	//void Print()
	//{
	//	cout << "(" << x << ", " << y << ") " << endl;
	//}

	Point operator+ (const Point& other)
	{
		return Point(x + other.x, y + other.y);
	}

	Point operator- (const Point& other)
	{
		return Point(x - other.x, y - other.y);
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

};

// 5 * p1; Scalar multiply point. Non member overload

Point operator* (int s, const Point& p) 
{
	return Point(p.x * s, p.y * s);
}

ostream& operator << (ostream& left, const Point& right)
{
	left << "(" << right.x << ", " << right.y << ")";
	return left;
}

int main() {

	Point p1(20, 50);
	Point p2(40, 20);
	Point p3(15, 10); 

	//Point p4 = p1.Add(p2.Subtract(p3));
	//p4.Print();

	Point p4 = p1 + p2 - p3;
	cout << p4;
	cout << -p4;

	Point p5 = p1 * 5;
	Point p6 = 5 * p1;

	cout << p5 << p6 << endl;

}