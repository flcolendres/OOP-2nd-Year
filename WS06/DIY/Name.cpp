/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 3, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Name.h"
using namespace std;
namespace sdds
{
   Name::Name()
   {
      m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
   }

   Name::Name(char* first)
   {
      if (!strcmp(first, " ") || !strcmp(first, ""))
      {
         m_nameFirst = nullptr;
      }
      else
      {
         m_nameFirst = new char[strlen(first) + 1];
         strcpy(m_nameFirst, first);
      }
   }

   Name::Name(char* first, char* last)
   {
      if (!strcmp(first, " ") || !strcmp(last, " ") ||
         !strcmp(first, "") || !strcmp(last, "") ||
         first == nullptr || last == nullptr)
      {
         m_nameFirst = m_nameLast = nullptr;
      }
      else
      {
         m_nameFirst = new char[strlen(first) + 1];
         m_nameLast = new char[strlen(last) + 1];
         strcpy(m_nameFirst, first);
         strcpy(m_nameLast, last);
      }
   }

   Name::Name(char* first, char* middle, char* last)
   {
      if (!strcmp(first, " ") || !strcmp(middle, " ") || !strcmp(last, " ") ||
         !strcmp(first, "") || !strcmp(middle, "") || !strcmp(last, "") ||
         first == nullptr || middle == nullptr || last == nullptr)
      {
         m_nameFirst = nullptr;
      }
      else
      {
         m_nameFirst = new char[strlen(first) + 1];
         m_nameMiddle = new char[strlen(middle) + 1];
         m_nameLast = new char[strlen(last) + 1];
         strcpy(m_nameFirst, first);
         strcpy(m_nameMiddle, middle);
         strcpy(m_nameLast, last);
      }
   }

   Name::Name(const Name& n)
   {
      if (bool(n))
      {
         m_nameFirst = new char[strlen(n.m_nameFirst) + 1];
         m_nameMiddle = new char[strlen(n.m_nameMiddle) + 1];
         m_nameLast = new char[strlen(n.m_nameLast) + 1];
         strcpy(m_nameFirst, n.m_nameFirst);
         strcpy(m_nameMiddle, n.m_nameMiddle);
         strcpy(m_nameLast, n.m_nameLast);
      }
   }

   Name& Name::operator=(const Name& n)
   {
      if (this != &n)
      {
         if (bool(n))
         {
            m_nameFirst = new char[strlen(n.m_nameFirst) + 1];
            m_nameMiddle = new char[strlen(n.m_nameMiddle) + 1];
            m_nameLast = new char[strlen(n.m_nameLast) + 1];
            strcpy(m_nameFirst, n.m_nameFirst);
            strcpy(m_nameMiddle, n.m_nameMiddle);
            strcpy(m_nameLast, n.m_nameLast);
         }
      }
      return *this;
   }

   Name::~Name()
   {
      delete[] m_nameFirst;
      delete[] m_nameMiddle;
      delete[] m_nameLast;
   }

   void Name::setShort(bool valid)
   {
      if (valid)
      {
         strcpy(m_nameMiddle, m_nameMiddle[0] + ".");
      }
   }

   Name& Name::operator+=(const char* input)
   {
      if (!strcmp(input, "") || input == nullptr)
      {
         if (m_nameFirst == nullptr)
         {
            m_nameFirst = new char[strlen(input) + 1];
            strcpy(m_nameFirst, input);
         }
         else if (m_nameMiddle == nullptr)
         {
            m_nameMiddle = new char[strlen(input) + 1];
            strcpy(m_nameMiddle, input);
         }
         else if (m_nameLast == nullptr)
         {
            m_nameLast = new char[strlen(input) + 1];
            strcpy(m_nameLast, input);
         }
         if (m_nameFirst != nullptr && m_nameMiddle != nullptr && m_nameLast != nullptr)
         {
            m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
         }
         else if (strstr(input, " "))
         {
            m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
         }
      }

      return *this;
   }
   Name::operator bool() const
   {
      return m_nameFirst != nullptr;
   }
   istream& Name::operator>>(istream istr)
   {
      return istr;
   }
   ostream& Name::operator<<(ostream ostr) const
   {
      if (bool(*this))
      {
         ostr << m_nameFirst << " ";
         if (m_nameMiddle != nullptr)
         {
            ostr << m_nameMiddle << " ";
         }
         if (m_nameLast != nullptr)
         {
            ostr << m_nameLast;
         }
      }
      return ostr;
   }
}