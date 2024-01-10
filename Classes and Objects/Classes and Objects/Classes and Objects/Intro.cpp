#include <iostream>
#include <string>
using namespace std;

class Car
{
public:

	string m_brand;
	int m_year;
	int m_miles;

	void display()
	{
		cout << "Brand: " << m_brand << endl;
		cout << "Year: " << m_year << endl;
		cout << "Miles: " << m_miles << endl;
	}
	
	void drive(int miles)
	{
		m_miles = m_miles + miles;
	}

	Car()
	{
		cout << "Default Constructor." << endl;
	}

	~Car()
	{
		cout << "Default Destructor." << endl;
	}
};

int main() {

	Car* myCar = new Car;
	(*myCar).m_brand = "Ford";
	(*myCar).m_year = 2022;
	(*myCar).m_miles = 40'000;
	(*myCar).display();
	delete myCar;
	myCar = nullptr;

	Car* pMyCar1 = new Car;

	if (pMyCar1 != nullptr)
	{
		Car myCar1; // statically allocating a constructor to generate myCar1, once the if statement is complete, a destructor is called as it is not longer needed.
	}

	delete pMyCar1;

}