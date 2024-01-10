#include <iostream>
#include <string>
using namespace std;

class Car
{
private:

	string m_brand;
	int m_year;
	int m_miles;

public:

	void set_m_brand(string m_brand) { this->m_brand = m_brand; }
	string get_m_brand() { return m_brand; }
	void set_m_year(int m_year) { this->m_year = m_year; }
	int get_m_year() { return m_year; }
	void set_m_miles(int m_miles) { this->m_miles = m_miles; }
	int get_m_miles() { return m_miles; }
	void display(Car source){
		cout << "Brand: " << source.get_m_brand() << endl;
		cout << "Year: " << source.get_m_year() << endl;
		cout << "Miles: " << source.get_m_miles() << endl;
	}
	void drive(int miles){m_miles = m_miles + miles;}
	Car(string m_brand = "Ford", int m_year = 1998, int m_miles = 40'000);
	Car(const Car& source);
	~Car(){cout << "Default Destructor." << endl;}
};

Car::Car(string m_brand, int m_year, int m_miles)
	: m_brand{ m_brand }, m_year{ m_year }, m_miles{ m_miles } {
	cout << "3 Args Constructor Called" << endl; }

Car::Car(const Car& source)
	: m_brand(source.m_brand), m_year(source.m_year), m_miles(source.m_miles) {
	cout << "Copy Constructor Called." << endl;
}

int main() {

	Car myCar;
	myCar.set_m_brand("Ferrari");
	myCar.display(myCar);
	Car myCar2{ myCar };


	Car* pMyCar = new Car;
	pMyCar->display(myCar);
	delete pMyCar;
	pMyCar = nullptr;


}