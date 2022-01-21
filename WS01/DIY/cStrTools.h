#ifndef SDDS_CSTRTOOLS_H
#define SDDS_CSTRTOOLS_H
namespace sdds {

	char toLower(char ch);
	void toLowerCaseAndCopy(char des[], const char source[]);
	int strLen(const char* str);
	void strCpy(char* des, const char* src);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	const char* strStr(const char* str, const char* find);
}

#endif