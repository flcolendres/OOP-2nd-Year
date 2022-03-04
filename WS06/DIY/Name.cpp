/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 3, 2022
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
         m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
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
         m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
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
      if (bool(n))
      {
         m_nameFirst = new char[strlen(n.m_nameFirst) + 1];
         strcpy(m_nameFirst, n.m_nameFirst);
         m_nameMiddle = new char[strlen(n.m_nameMiddle) + 1];
         strcpy(m_nameMiddle, n.m_nameMiddle);
         m_nameLast = new char[strlen(n.m_nameLast) + 1];
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
            strcpy(m_nameFirst, n.m_nameFirst);
            m_nameMiddle = new char[strlen(n.m_nameMiddle) + 1];
            strcpy(m_nameMiddle, n.m_nameMiddle);
            m_nameLast = new char[strlen(n.m_nameLast) + 1];
            strcpy(m_nameLast, n.m_nameLast);
         }
      }
      return *this;
   }

   Name::~Name()
   {
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
      return m_nameFirst != nullptr;
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