/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

	void Flight::emptyPlane() {
		m_passengers = 0;
		m_fuel = 0;
		strcpy(m_title, "EmptyPlane");
	}

	// New Flight
	Flight::Flight() {
		emptyPlane();
	}
	Flight::Flight(int passengers, double fuel, const char* title) {
		emptyPlane();
		if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
			fuel <= FuelTankCapacity) {
			m_passengers = passengers;
			m_fuel = fuel;
			strcpy(m_title, title);
		}
	}
	std::ostream& Flight::display() const {

		if (*this) {
			cout << " Flight  |  Ready to Depart";
			cout << " ";
			cout.width(10);
			cout << std::string(*this);
			cout << " | ";
			cout << "Pass: ";
			cout.width(10);
			cout << int(*this);
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << double(*this);
			cout.unsetf(ios::right);
			cout << " Liters";
		}
		else if (~*this) {
			cout << " Flight  |  Empty Plane    ";
		}
		else {
			cout << " Flight  |  Low Fuel       ";
			cout << " ";
			cout.width(10);
			cout << (const char*)(*this);
			cout << " | ";
			cout << "Pass: ";
			cout.width(10);
			cout << int(*this);
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << double(*this);
			cout.unsetf(ios::right);
			cout << " Liters";
		}
		return cout;
	}

	Flight::operator bool() const
	{
		return m_passengers > 0 && m_fuel >= m_passengers * 600;
	}

	Flight::operator int() const
	{
		return m_passengers;
	}

	Flight::operator double() const
	{
		return m_fuel;
	}

	Flight::operator std::string() const
	{
		return m_title;
	}
	bool Flight::operator~() const
	{
		return m_passengers == 0;
	}

	Flight& Flight::operator=(Flight& f)
	{
		m_passengers = f.m_passengers;
		m_fuel = f.m_passengers;
		strcpy(m_title, f.m_title);
		f.emptyPlane();
		return *this;
	}

	Flight& Flight::operator=(int i)
	{
		if (i > 0 && i <= Boen747Capacity)
			m_passengers = i;
		return *this;
	}
	Flight& Flight::operator=(double d)
	{
		if (d > 0 && d < FuelTankCapacity)
			m_fuel = d;
	}
	Flight& Flight::operator+=(double d)
	{
		while (d > 0 && m_fuel < FuelTankCapacity)
		{
			d--;
			m_fuel++;
		}
		return *this;
	}
	Flight& Flight::operator+=(int i)
	{
		while (i > 0 && m_passengers < Boen747Capacity)
		{
			i--;
			m_passengers++;
		}
		return *this;
	}

	Flight& Flight::operator-=(double d)
	{
		while (d > 0 && m_fuel > 0)
		{
			d--;
			m_fuel--;
		}
		return *this;
	}

	Flight& Flight::operator-=(int i)
	{
		while (i > 0 && m_passengers > 0)
		{
			i--;
			m_passengers++;
		}
		return *this;
	}




}