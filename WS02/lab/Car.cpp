/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Jan. 23, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Car.h"
#include "cStrTools.h"

using namespace std;
namespace sdds {

	Car* cars;
	int allSize;
	int numOfCars;
	int carArrSize;

	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry" << endl << "Enter the data in the following format:" << endl << "Make and model, LicensePlate, MilitaryTime<ENTER>" << endl <<
			"Exit the program by entering the following:" << endl << "X,<ENTER>" << endl;
	}
	void initialize(int allocSize) {
		numOfCars = 0;
		carArrSize = allSize = allocSize;
		cars = new Car[allSize];
	}
	void deallocate(Car& C) {
		delete[] C.makeAndModel;
		C.makeAndModel = nullptr;
	}
	bool read(Car& C) {
		bool valid = false;
		char cString[60 + 1] = { 0 };
		read(cString, 60 + 1, ',');
		if (strCmp(cString, "X")) {
			valid = true;
			C.makeAndModel = new char[60 + 1];
			strCpy(C.makeAndModel, cString);
			read(C.licensePlate, 8 + 1, ',');
			cin >> C.time;
		}
		return valid;
	}
	void print(const Car& C) {
		cout << C.time << ": " << C.makeAndModel << "," << C.licensePlate << endl;
	}
	void record(const Car& C) {
		int i;

		if (numOfCars == carArrSize) {
			Car* tempCars = new Car[carArrSize + allSize];
			for (i = 0; i < numOfCars; i++) {
				tempCars[i] = cars[i];
			}
			delete[] cars;
			cars = tempCars;
			carArrSize += allSize;
		}
		cars[numOfCars] = C;
		numOfCars++;

	}
	void endOfDay() {
		int i;
		for (i = 0; i < numOfCars; i++) {
			print(cars[i]);
			deallocate(cars[i]);
		}
		delete[] cars;
		cars = nullptr;
	}
}