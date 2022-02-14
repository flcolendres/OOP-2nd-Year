/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 7, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

	const int Boen747Capacity = 388;
	const int FuelTankCapacity = 238840;

	class Flight {

		int m_passengers = 0;
		double m_fuel = 0;
		char m_title[16];
		void emptyPlane();

	public:
		Flight();
		Flight(int passengers, double fuel, const char* title);
		std::ostream& display()const;
		operator bool()const;
		operator int()const;
		operator double()const;
		operator const char*()const;
		bool operator ~() const;
		Flight& operator=(Flight& f);
		Flight& operator=(int i);
		Flight& operator=(double d);
		Flight& operator+=(double& d);
		Flight& operator+=(int& i);
		Flight& operator-=(double& d);
		Flight& operator-=(int& i);
		Flight& operator<<(Flight& f);
		Flight& operator>>(Flight& f);
	};
	int operator+(const Flight& left, const Flight& right);
	int operator+=(int& left, const Flight& right);
}
#endif // SDDS_FLIGHT_H