/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Jan. 23, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TRAIN_H 
#define SDDS_TRAIN_H

namespace sdds
{
	class Train
	{
		const int MAX_NAME_LEN = 20;
		const int MAX_PEOPLE = 1000;
		const int MAX_SPEED = 320;
		char trainName[20 + 1] = { 0 };
		int numPeople;
		double trainSpeed;
	
	public:
		void set(const char*, int, double);
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		void display() const;

	};


}

#endif