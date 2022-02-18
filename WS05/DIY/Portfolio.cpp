/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 17, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"

using namespace std;
namespace sdds {


	Portfolio::Portfolio() {
		emptyPortfolio();
	}

	void Portfolio::emptyPortfolio()
	{
		m_value = 0;
		m_stock[0] = 0;
		m_type = 'E';
	}
	Portfolio::Portfolio(double value, const char* stock, char type) {
		emptyPortfolio();
		if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
			m_value = value;
			m_type = type;
			strcpy(m_stock, stock);
		}
	}

	void Portfolio::dispPortfolio() const {
		cout << " ";
		cout.width(10);
		cout << (const char*)(*this);
		cout << " | ";
		cout << "Value: ";
		cout.width(10);
		cout << double(*this);
		cout << " | ";
		cout << " Type: ";
		cout << char(*this);
	}
	std::ostream& Portfolio::display() const {

		if (~*this) {
			cout << " Portfolio  |  Bad-NG |";
			dispPortfolio();
		}
		else if (*this) {
			cout << " Portfolio  |  Active |";
			dispPortfolio();

		}
		else {
			cout << " Portfolio  |  EMPTY  |";
			dispPortfolio();
		}
		return cout;
	}

	Portfolio::operator double() const
	{
		return (double)m_value;
	}

	Portfolio::operator const char* () const
	{
		return (const char*)m_stock;
	}

	Portfolio::operator char() const
	{
		return (char)m_type;
	}

	Portfolio::operator bool() const
	{
		return m_type == 'G' || m_type == 'V' || m_type == 'I';
	}

	Portfolio& Portfolio::operator+=(const double right)
	{
		if ((*this && !~*this) && right > 0)
		{
			m_value += right;
		}
		return *this;
	}

	Portfolio& Portfolio::operator-=(const double right)
	{
		if ((*this && !~*this) && right > 0)
		{
			m_value -= right;
		}
		return *this;
	}

	bool Portfolio::operator~() const
	{
		return m_value < 0;
	}

	Portfolio& Portfolio::operator<<(Portfolio& right)
	{
		if ((*this && !~*this) && (right && !~right))
		{
			m_value += right.m_value;
			right.emptyPortfolio();
		}
		return *this;
	}

	Portfolio& Portfolio::operator>>(Portfolio& right)
	{
		if ((*this && !~*this) && (right && !~right))
		{
			right.m_value += m_value;
			this->emptyPortfolio();

		}
		return right;
	}

	double operator+(const Portfolio& left, const Portfolio& right)
	{
		double result = 0;
		if ((left && !~left) && (right && !~right))
			result = (double)left + (double)right;
		return result;
	}

	double operator+=(double& left, const Portfolio& right)
	{
		return left += (double)right;
	}

}