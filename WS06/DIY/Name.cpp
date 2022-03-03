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

namespace sdds
{
   Name::Name()
   {
      m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
   }

   Name::Name(char* first)
   {
      if (!strcmp(first, " "))
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
      if (!strcmp(first, " ") || !strcmp(last, " ") )
      {
         m_nameFirst = nullptr;
      }
      else
      {
         m_nameFirst = new char[strlen(first) + 1];
         strcpy(m_nameFirst, first);
      }
   }

   Name::Name(char* first, char* middle, char* last)
   {
   }

   Name::Name(const Name& n)
   {
   }

   Name& Name::operator=(const Name& n)
   {
      // TODO: insert return statement here
   }

  Name::~Name()
   {
   }
}