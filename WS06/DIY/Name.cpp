/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 27, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <cstring>
#include "Name.h"
using namespace std;
namespace sdds
{


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
         m_nameFirst = nullptr;
      }
      else
      {
         m_nameFirst = new char[strlen(first) + 1];
         strcpy(m_nameFirst, first);
      }
   }

   Name::Name()
   {
      m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
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
         strcpy(m_nameFirst, first);
         m_nameMiddle = new char[strlen(middle) + 1];
         strcpy(m_nameMiddle, middle);
         m_nameLast = new char[strlen(last) + 1];
         strcpy(m_nameLast, last);

      }
   }

   Name::Name(const Name& n)
   {

   }

   Name::~Name()
   {
   }

   Name& Name::operator=(const Name& n)
   {
      return *this;
   }

   void Name::setShort(bool valid)
   {
   }
   Name& Name::operator+=(const Name& n)
   {
      // TODO: insert return statement here
   }
   Name::operator bool() const
   {
      return !strcmp(m_nameFirst, " ") || !strcmp(m_nameMiddle, " ") || !strcmp(m_nameLast, " ") ||
         !strcmp(m_nameFirst, "") || !strcmp(m_nameMiddle, "") || !strcmp(m_nameLast, "") ||
         m_nameFirst == nullptr || m_nameMiddle == nullptr || m_nameLast == nullptr;
   }
   std::istream& operator>>(std::istream istr, Name& n)
   {
      // TODO: insert return statement here
   }
   std::ostream& operator<<(std::ostream ostr, const Name& n)
   {
      // TODO: insert return statement here
   }
}