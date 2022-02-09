/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 7, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
#include "CarInventory.h"

using namespace std;
namespace sdds
{
	void CarInventory::resetInfo()
	{
		m_type = m_brand = m_model = nullptr;
		m_year = m_code = 0;
		m_price = 0;
	}
	CarInventory::CarInventory()
	{
		resetInfo();
	}

	CarInventory::~CarInventory()
	{
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		resetInfo();
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		m_type = new char[10 + 1];
		strcpy(m_type, type);
		m_brand = new char[10 + 1];
		strcpy(m_brand, brand);
		m_model = new char[10 + 1];
		strcpy(m_model, model);

		if (m_type != nullptr && m_brand != nullptr && m_model != nullptr)
		{
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else
		{
			resetInfo();
		}
	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;

		m_type = new char[10 + 1];
		strcpy(m_type, type);
		m_brand = new char[10 + 1];
		strcpy(m_brand, brand);
		m_model = new char[10 + 1];
		strcpy(m_model, model);

		m_year = year;
		m_code = code;
		m_price = price;
		return *this;
	}

	void CarInventory::printInfo() const
	{
		cout.setf(ios::left);
		cout.setf(ios::fixed);
		cout.precision(2);

		cout << "| ";
		cout.width(11);
		cout << m_type << "| ";
		cout.width(17);
		cout << m_brand << "| ";
		cout.width(17);
		cout << m_model << "| ";
		cout.width(4);
		cout << m_year << " | ";
		cout.unsetf(ios::left);
		cout.width(4);
		cout << m_code;
		cout << " | ";
		cout.width(9);
		cout << m_price << " |" << endl;


	}

	bool CarInventory::isValid() const
	{
		bool result = false;
		if (m_type != nullptr && m_brand != nullptr
			&& m_model != nullptr
			&& m_year >= 1990
			&& m_code > 99
			&& m_code < 1000
			&& m_price > 0)
		{
			result = true;
		}
		return result;
	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{
		bool result = false;
		// check if values are not null before comparing the strings
		if (m_type != nullptr && m_brand != nullptr
			&& m_model != nullptr)
		{
			if (!strcmp(m_type, car.m_type) && 
				!strcmp(m_brand, car.m_brand) && 
				!strcmp(m_model, car.m_model) && 
				m_year == car.m_year)
			{
				result = true;
			}
		}
		return result;
	}

	bool find_similar(CarInventory car[], const int num_cars)
	{
		bool result = false;
		for (int i = 0; i < num_cars; i++)
		{
			for (int j = i + 1; j < num_cars; j++)
			{
				if (car[i].isSimilarTo(car[j]))
				{
					result = true;
				}
			}
		}
		return result;
	}

}
