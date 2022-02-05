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

		// the data values received are invalid and 
		// therefore requires all variables to be set to safe empty state (-1)
		if (valid != 3)
		{
			for (i = 0; i <= MAX_NAME_LEN; i++)
				m_trainName[i] = 0;

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
		bool valid = false;

		// the following conditions define an object in safe empty state
		if ((m_numPeople < 0 || m_numPeople > MAX_PEOPLE) && (m_trainSpeed < 0 || m_trainSpeed > MAX_SPEED))
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
		if (isSafeEmpty())
		{
			valid = false;
		}
		else
		{
			if (numPeople > MAX_PEOPLE)
			{
				m_numPeople = MAX_PEOPLE;
			}
			else if (numPeople < 0)
			{
				m_numPeople = 0;
			}
			else
			{

				m_numPeople = numPeople;
			}
		}


		return valid;
	}
	bool Train::changeSpeed(double input)
	{
		bool valid = true;
		double trainSpeed = getSpeed() + input;
		if (isSafeEmpty())
		{
			valid = false;
		}
		else
		{
			if (trainSpeed > MAX_SPEED)
			{
				m_trainSpeed = MAX_SPEED;
			}
			else if (trainSpeed < 0)
			{
				m_trainSpeed = 0;
			}
			else
			{
				m_trainSpeed = trainSpeed;
			}
		}
		return valid;
	}
	int transfer(Train& trainA, Train& trainB)
	{
		int i;
		int numPeopleA = trainA.getNumberOfPeople();
		int numPeopleB = trainB.getNumberOfPeople();

		if (trainA.isSafeEmpty() || trainB.isSafeEmpty())
		{
			i = -1;
		}
		else
		{
			for (i = 0; i < numPeopleB && numPeopleA != MAX_PEOPLE; i++)
			{
				trainA.loadPeople(1);
				trainB.loadPeople(-1);
				numPeopleA = trainA.getNumberOfPeople();
				numPeopleB = trainB.getNumberOfPeople();
			}
		}

		return i;
	}

}