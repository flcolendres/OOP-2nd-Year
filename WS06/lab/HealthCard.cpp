/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 27, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HealthCard.h"
using namespace std;

namespace sdds
{
   bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
   {
      return name != nullptr && strlen(name) > 0 &&
         number > 999999999 && number < 9999999999 &&
         strlen(vCode) == 2 + 1 && strlen(sNumber) == 9 + 1; // +1 for null terminator 
   }
   void HealthCard::setEmpty()
   {
      m_name = nullptr;
   }
   void HealthCard::allocateAndCopy(const char* name)
   {
      delete[] m_name;
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);
   }
   ostream& HealthCard::printIDInfo(ostream& ostr) const
   {
      ostr << m_name << "-" << m_vCode << ", " << m_sNumber;
      return ostr;
   }
   void HealthCard::extractChar(std::istream& istr, char ch) const
   {
      char next;
      next = istr.peek();
      if (next == ch)
         istr.ignore();
      else
      {
         istr.ignore(1000, ch);
         istr.setstate(ios::failbit);
      }
   }
   void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
   {

   }
   HealthCard::HealthCard()
   {
   }
   HealthCard::HealthCard(const HealthCard& hc)
   {
   }
   HealthCard& HealthCard::operator=(const HealthCard& hc)
   {
      return *this;
   }
   HealthCard::~HealthCard()
   {
   }
   HealthCard::operator bool()
   {
      return false;
   }
   ostream& HealthCard::print(ostream& ostr, bool toFile) const
   {
      return ostr;
   }
   istream& HealthCard::read(istream& istr)
   {
      return istr;
   }
   ostream& operator<<(ostream& ostr, const Contact& hc)
   {
      return ostr;
   }
   istream& operator>>(istream& istr, Contact& hc)
   {
      return istr;
   }
}
