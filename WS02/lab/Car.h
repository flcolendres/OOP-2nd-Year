/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Jan. 23, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
namespace sdds {

	struct Car {
		char licensePlate[8 + 1];
		char* makeAndModel;
		int time;
	};

	void VBPLE_Title();
	void initialize(int allocSize);
	void deallocate(Car& C);
	bool read(Car& C);
	void print(const Car& C);
	void record(const Car& C);
	void endOfDay();

}
#endif