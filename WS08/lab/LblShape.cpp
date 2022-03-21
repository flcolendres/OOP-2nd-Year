/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 21, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"
using namespace std;
namespace sdds
{
   LblShape::LblShape(const char* cstr)
   {
      m_label = new char(strlen(cstr) + 1);
      strcpy(m_label, cstr);
   }
   void LblShape::getSpecs(istream& istr)
   {
      char input[1000];
      istr >> input;
      istr.ignore(',');
      m_label = new char(strlen(input) + 1);
      strcpy(m_label, input);
   }
}