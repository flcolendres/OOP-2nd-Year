/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Jan. 23, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Train.h"
#include <iostream>
using namespace std;
namespace sdds
{
	void Train::set(const char*, int, double)
	{

	}
	int Train::getNumberOfPeople() const
	{
		return 0;
	}
	const char* Train::getName() const
	{
		return nullptr;
	}
	double Train::getSpeed() const
	{
		return 0.0;
	}
	void Train::display() const
	{
		cout << "NAME OF THE TRAIN : " << trainName << endl
			<< "NUMBER OF PEOPLE : " << numPeople << endl;
		cout.precision(2);
		cout << "SPEED : " << trainSpeed << " km / h" << endl;
			
	}
}