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
         strlen(vCode) == 2 && strlen(sNumber) == 9;
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
      ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
      return ostr;
   }
   void HealthCard::extractChar(istream& istr, char ch) const
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
   HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
   {
      set(name, number, vCode, sNumber);
   }
   void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
   {
      if (validID(name, number, vCode, sNumber))
      {
         allocateAndCopy(name);
         m_number = number;
         strcpy(m_vCode, vCode);
         strcpy(m_sNumber, sNumber);
      }
      else
      {
         delete[] m_name;
         setEmpty();
      }
   }
   HealthCard::HealthCard(const HealthCard& hc)
   {
      if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber))
      {
         allocateAndCopy(hc.m_name);
         m_number = hc.m_number;
         strcpy(m_vCode, hc.m_vCode);
         strcpy(m_sNumber, hc.m_sNumber);
      }
   }
   HealthCard& HealthCard::operator=(const HealthCard& hc)
   {
      if (this != &hc)
      {
         if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber))
         {
            allocateAndCopy(hc.m_name);
            m_number = hc.m_number;
            strcpy(m_vCode, hc.m_vCode);
            strcpy(m_sNumber, hc.m_sNumber);
         }
      }
      return *this;
   }
   HealthCard::~HealthCard()
   {
      delete[] m_name;
   }
   HealthCard::operator bool() const
   {
      return m_name != nullptr;
   }
   ostream& HealthCard::print(ostream& ostr, bool toFile) const
   {
      if (validID(m_name, m_number, m_vCode, m_sNumber))
      {
         if (toFile)
         {
            ostr << m_name << ",";
            printIDInfo(ostr);
         }
         else
         {
            ostr.setf(ios::left);
            ostr.fill('.');
            ostr.width(50);
            ostr << m_name;
            printIDInfo(ostr);
         }
      }
      return ostr;
   }
   istream& HealthCard::read(istream& istr)
   {
      char name[MaxNameLength + 1];
      long long number;
      char vCode[3];
      char sNumber[10];

      istr.get(name, MaxNameLength, ',');
      extractChar(istr, ',');
      istr >> number;
      extractChar(istr, '-');
      istr.get(vCode, 3, ',');
      extractChar(istr, ',');
      istr.get(sNumber, 10, '\n');
      if (!istr.fail())
      {
         set(name,number,vCode,sNumber);
      }
      istr.clear();
      istr.ignore(1000, '\n');
      return istr;
   }
   ostream& operator<<(ostream& ostr, const HealthCard& hc)
   {
      if (bool(hc))
      {
         hc.print(ostr);
      }
      else
      {
         ostr << "Invalid Card Number";
      }
      return ostr;
   }
   istream& operator>>(istream& istr, HealthCard& hc)
   {
      return hc.read(istr);
   }
}
