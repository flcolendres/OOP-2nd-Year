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
		cout << "Vehicle Border Passing Log Entry" << endl << "Enter the data in the following format:" << "Make and model, LicensePlate, MilitaryTime" <<
			"Exit the program by entering the following:" << endl << "X," << endl;
	}
	void initialize(int allocSize) {
		numOfCars = 0;
		carArrSize = allSize = allocSize;
		cars = new Car[allSize];
	}

}