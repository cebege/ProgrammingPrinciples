// Functions

// Structure : returnType Identifier (parameters).
// function declaration (with semi colon) and function definition (semi colon).
// Overloarding Polymorphism!

#include <iostream>
#include <string>

using namespace std;

const double pi{ 3.142 };
double calc_area_circle(double radius);
double calc_volume_cylinder(double radius, double height);
void area_circle();
void volume_cyclinder();

int main() {

	area_circle();
	volume_cyclinder();

	return 0;
}


double calc_area_circle(double radius)
{
	return pi * radius * radius;
}

double calc_volume_cylinder(double radius, double height)
{
	return pi * radius * radius * height;
}

void area_circle() {
	double radius{};
	cout << "\nEnter radius of the circle: ";
	cin >> radius;

	cout << "The area of a circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

void volume_cyclinder() {
	double radius{};
	double height{};
	cout << "\nEnter radius of circle: ";
	cin >> radius;
	cout << "\nEnter height of cyclinder: ";
	cin >> height;

	cout << "The volume of a cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height) << endl;
}
