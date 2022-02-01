/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Jan. 23, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Train.h"
#include <iostream>
#include <string.h>
using namespace std;
namespace sdds
{
	void Train::set(const char* trainName, int numPeople, double trainSpeed)
	{
		int i, valid = 0;

		if (trainName != nullptr && strlen(trainName) > 0)
		{
			strncpy(m_trainName, trainName, MAX_NAME_LEN);
			valid++;
		}
		if (numPeople > 0 && numPeople <= MAX_PEOPLE)
		{
			m_numPeople = numPeople;
			valid++;
		}
		if (trainSpeed > 0 && trainSpeed <= MAX_SPEED)
		{
			m_trainSpeed = trainSpeed;
			valid++;
		}

		// Sets the objects to a safe empty state (zero)
		if (valid != 3) 
		{
			for (i = 0; i <= MAX_NAME_LEN; i++)
				m_trainName[i] = 0;
			m_numPeople = 0;
			m_trainSpeed = 0;
		}

	}
	int Train::getNumberOfPeople() const
	{
		return m_numPeople;
	}
	const char* Train::getName() const
	{
		return m_trainName;
	}
	double Train::getSpeed() const
	{
		return m_trainSpeed;
	}
	bool Train::isSafeEmpty() const
	{
		// The OOP244 website suggests to choose one data member to hold the special value that identifies an empty state
		// Therefore, I only chose the m_numPeople to determine whether the object is a safe empty state
		// Source: https://ict.senecacollege.ca/~oop244/pages/content/cppst.html#saf
		bool valid = false;

		if (!m_numPeople)
			valid = true;

		return valid;
	}
	void Train::display() const
	{
		if (isSafeEmpty())
		{
			cout << "Safe Empty State!" << endl;
		}
		else
		{
			cout.width(10);
			cout << "NAME OF THE TRAIN : " << m_trainName << endl;
			cout << "NUMBER OF PEOPLE  : " << m_numPeople << endl;
			cout << "SPEED";
			cout.setf(ios::fixed);
			cout.width(15);
			cout.precision(2);
			cout << ": " << m_trainSpeed << " km/h" << endl;
		}

	}
}