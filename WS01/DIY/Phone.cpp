/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Jan. 21, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "Phone.h"
#include "cStrTools.h"
using namespace std;
namespace sdds {

	// displays title
	void title(const char* programTitle) {
		cout << programTitle << " phone directory search" << endl << "-------------------------------------------------------" << endl;
	}
	// displays thank you message.
	void thankYou(const char* programTitle) {
		cout << "Thank you for using " << programTitle << " directory." << endl;
	}
	// runs the phone directory appication
	void phoneDir(const char* programTitle, const char* fileName) {
		int i = 0;
		Contacts contacts[MAX_NO_OF_CONTACTS] = { 0 };
		List contactList = { contacts };
		FILE* fptr = fopen(fileName, "r");

		if (fptr) {
			while (fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n",
				contacts[i].name,
				contacts[i].area,
				contacts[i].prefix,
				contacts[i].number) == 4) {
				i++;
			}
			fflush(fptr);
			fclose(fptr);
			title(programTitle);
			enterProgram(&contactList);
		}
		else {
			cout << fileName << " file not found!" << endl;
		}
		thankYou(programTitle);

	}
	// prompt user for partial name entry if data file is successfully opened.
	void enterProgram(List* contactList) {
		int i;
		int exit = 0;
		char input[50];
		char inputLowerCase[50];
		char nameLowerCase[50];

		while (!exit) {
			cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl << "> ";
			cin >> input;
			if (strCmp(input, "!") == 0) {
				exit++;
			}
			else
			{
				toLowerCaseAndCopy(inputLowerCase, input);
				for (i = 0; i < MAX_NO_OF_CONTACTS; i++) {

					toLowerCaseAndCopy(nameLowerCase, contactList->contacts[i].name);
					if (strStr(nameLowerCase, inputLowerCase)) {
						cout << contactList->contacts[i].name << ": "
							<< "(" << contactList->contacts[i].area << ") "
							<< contactList->contacts[i].prefix << "-"
							<< contactList->contacts[i].number << endl;
					}

				}
			}
		}
	}
}