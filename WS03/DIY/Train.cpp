/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 1, 2022
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

		if (trainName != nullptr && strlen(trainName) >= 0)
		{
			strncpy(m_trainName, trainName, MAX_NAME_LEN);
			valid++;
		}
		if (numPeople >= 0 && numPeople <= MAX_PEOPLE)
		{
			m_numPeople = numPeople;
			valid++;
		}
		if (trainSpeed >= 0 && trainSpeed <= MAX_SPEED)
		{
			m_trainSpeed = trainSpeed;
			valid++;
		}

		if (valid != 3)
		{
			for (i = 0; i <= MAX_NAME_LEN; i++)
			m_trainName[i] = 0;
			// the data values received are invalid and 
			// therefore requires all variables to be set to safe empty state
			m_numPeople = -1; 
			m_trainSpeed = -1;
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

		if (m_numPeople < 0)
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
	bool Train::loadPeople(int input)
	{
		bool valid = true;
		int numPeople = getNumberOfPeople() + input;
		if (numPeople < 0 || numPeople > MAX_PEOPLE)
		{
			valid = false;
		}
		else
		{
			m_numPeople = numPeople;
		}


		return valid;
	}
	bool Train::changeSpeed(double input)
	{
		bool valid = true;
		double trainSpeed = getSpeed() + input;
		if (trainSpeed < 0 || trainSpeed > MAX_SPEED) 
		{
			valid = false;
		}
		else
		{
			m_trainSpeed = trainSpeed;
		}
		return valid;
	}

	int transfer(Train& trainA, Train& trainB)
	{
		int count;
		int numPeopleA = trainA.getNumberOfPeople();
		double numPeopleB = trainB.getNumberOfPeople();
		if (!(numPeopleA < 0 || numPeopleA > MAX_SPEED) && !(numPeopleB < 0 || numPeopleB > MAX_SPEED))
		{

		}
		return 0;
	}

}