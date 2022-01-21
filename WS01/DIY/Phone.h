/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Jan. 21, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PHONE_H
#define SDDS_PHONE_H
namespace sdds {
	const int MAX_NO_OF_CONTACTS = 36;

	struct Contacts {
		char name[51];
		char area[4];
		char prefix[4];
		char number[5];
	};
	struct List {
		Contacts* contacts; //array of contacts
	};

	// displays title
	void title(const char* programTitle);
	// displays thank you message.
	void thankYou(const char* programTitle);
	// runs the phone directory appication
	void phoneDir(const char* programTitle, const char* fileName);
	// prompt user for partial name entry if data file is successfully opened.
	void enterProgram(List* contactList);

}

#endif
