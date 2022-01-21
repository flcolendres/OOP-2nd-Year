/*
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Jan. 21, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CSTRTOOLS_H
#define SDDS_CSTRTOOLS_H
namespace sdds {

	// returns the lower case value of a character
	char toLower(char ch);
	// copies the  lower case version of the source into des.
	void toLowerCaseAndCopy(char des[], const char source[]);
	// returns the length of str
	int strLen(const char* str);
	// copies src to des
	void strCpy(char* des, const char* src);
	// compares s1 and s2 cStrings and returns:
	// > 0 if s1 > s2
	// < 0 if s1 < s3
	// == 0 if s1 == s2
	int strCmp(const char* s1, const char* s2);
	// compares s1 and s2 cStrings upto len characters and returns:
	// > 0 if s1 > s2
	// < 0 if s1 < s3
	// == 0 if s1 == s2
	int strnCmp(const char* s1, const char* s2, int len);
	// if "find" is found in "str" it will return the addres of the match
	// if not found it will returns nullptr (zero)
	const char* strStr(const char* str, const char* find);
}

#endif