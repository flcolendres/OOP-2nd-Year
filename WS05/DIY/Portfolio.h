/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.h
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
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

	class Portfolio {
		double m_value = 0;
		char m_stock[16];
		char m_type;
	public:
		Portfolio();
		void emptyPortfolio();
		Portfolio(double value, const char* stock, char type);
		void dispPortfolio()const;
		std::ostream& display() const;
		operator double() const;
		operator const char* ()const;
		operator char() const;
		operator bool() const;
		Portfolio& operator+=(const double right);
		Portfolio& operator-=(const double right);
		bool operator~()const;
		Portfolio& operator<<(Portfolio& right);
		Portfolio& operator>>(Portfolio& right);
	};
	double operator+(const Portfolio& left, const Portfolio& right);
	double operator+=(double& left, const Portfolio& right);
}
#endif // SDDS_Portfolio_H_