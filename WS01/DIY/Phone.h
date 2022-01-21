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
