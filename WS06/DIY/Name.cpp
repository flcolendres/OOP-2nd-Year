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
#include <string>
#include "Name.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
   Name::Name()
   {
      m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
   }

   Name::Name(const char* first)
   {
      if (isEmpty(first))
      {
         m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
      }
      else
      {
         m_nameFirst = new char[strlen(first) + 1];
         strcpy(m_nameFirst, first);
      }
   }

   Name::Name(const char* first, const char* last)
   {
      if (isEmpty(first) || isEmpty(last) ||
         first == nullptr || last == nullptr)
      {
         m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
      }
      else
      {
         m_nameFirst = new char[strlen(first) + 1];
         m_nameLast = new char[strlen(last) + 1];
         strcpy(m_nameFirst, first);
         strcpy(m_nameLast, last);
      }
   }

   Name::Name(const char* first, const char* middle, const char* last)
   {
      if (isEmpty(first) || isEmpty(middle) || isEmpty(last) ||
         first == nullptr || middle == nullptr || last == nullptr)
      {
         m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
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
         m_nameFirst = new char[strlen(n.m_nameFirst) + 1];
         strcpy(m_nameFirst, n.m_nameFirst);
         if (n.m_nameMiddle != nullptr)
         {
            m_nameMiddle = new char[strlen(n.m_nameMiddle) + 1];
            strcpy(m_nameMiddle, n.m_nameMiddle);
         }
         if (n.m_nameLast != nullptr)
         {
            m_nameLast = new char[strlen(n.m_nameLast) + 1];
            strcpy(m_nameLast, n.m_nameLast);
         }
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
            if (n.m_nameMiddle != nullptr)
            {
               m_nameMiddle = new char[strlen(n.m_nameMiddle) + 1];
               strcpy(m_nameMiddle, n.m_nameMiddle);
            }
            if (n.m_nameLast != nullptr)
            {
               m_nameLast = new char[strlen(n.m_nameLast) + 1];
               strcpy(m_nameLast, n.m_nameLast);
            }
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
      if (valid && m_nameMiddle != nullptr)
      {
         const char abbrv[3] = { m_nameMiddle[0], '.', '\0' };
         strcpy(m_nameMiddle, abbrv);
      }
   }

   Name& Name::operator+=(const char* input)
   {
      if (m_nameFirst != nullptr && m_nameMiddle != nullptr && m_nameLast != nullptr && isEmpty(m_nameFirst))
      {
         m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
      }
      else if (!isEmpty(input) || input != nullptr)
      {
         if (m_nameFirst == nullptr || isEmpty(m_nameFirst))
         {
            m_nameFirst = new char[strlen(input) + 1];
            strcpy(m_nameFirst, input);
         }
         else if (m_nameMiddle == nullptr || isEmpty(m_nameMiddle))
         {
            m_nameMiddle = new char[strlen(input) + 1];
            strcpy(m_nameMiddle, input);
         }
         else if (m_nameLast == nullptr || isEmpty(m_nameLast))
         {
            m_nameLast = new char[strlen(input) + 1];
            strcpy(m_nameLast, input);
         }
      }


      return *this;
   }
   Name::operator bool() const
   {
      return m_nameFirst != nullptr;
   }

   std::ostream& Name::print(std::ostream& ostr) const
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
      return ostr;
   }

   std::istream& Name::read(std::istream& istr)
   {
      string str;
      int i, spaces;
      bool valid = true;
      char* cstr, * tkn;
      getline(istr, str, '\n');
      cstr = new char[str.length() + 1];
      strcpy(cstr, str.c_str());
      for (i = 0, spaces = 0; i < strlen(cstr); i++)
      {
         if (cstr[i] == ' ')
         {
            spaces++;
         }
      }
      tkn = strtok(cstr, " ");
      switch (spaces)
      {
      case 0:
         m_nameFirst = new char[strlen(tkn) + 1];
         strcpy(m_nameFirst, tkn);
         break;
      case 1:
         m_nameFirst = new char[strlen(tkn) + 1];
         strcpy(m_nameFirst, tkn);
         tkn = strtok(NULL, " ");
         m_nameLast = new char[strlen(tkn) + 1];
         strcpy(m_nameLast, tkn);
         break;
      case 2:
         m_nameFirst = new char[strlen(tkn) + 1];
         strcpy(m_nameFirst, tkn);
         tkn = strtok(NULL, " ");
         m_nameMiddle = new char[strlen(tkn) + 1];
         strcpy(m_nameMiddle, tkn);
         tkn = strtok(NULL, " ");
         m_nameLast = new char[strlen(tkn) + 1];
         strcpy(m_nameLast, tkn);
         break;
      default:
         m_nameFirst = m_nameMiddle = m_nameLast = nullptr;
         break;
      }
      delete[] cstr;
      return istr;
   }

   std::ostream& operator<<(std::ostream& ostr, const Name& n)
   {
      if (bool(n))
      {
         n.print(ostr);
      }
      else
      {
         ostr << "Bad Name";
      }
      return ostr;
   }

   istream& operator>>(std::istream& istr, Name& N)
   {
      return N.read(istr);
   }

}