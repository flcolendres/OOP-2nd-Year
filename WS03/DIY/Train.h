/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 1, 2022
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
		char m_trainName[20 + 1];
		int m_numPeople;
		double m_trainSpeed;
	
	public:
		void set(const char* trainName, int numPeople, double trainSpeed);
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		void display() const;
		bool loadPeople(int input);
		bool changeSpeed(double input);
	};
	extern int transfer(Train trainA, Train trainB);

}

#endif