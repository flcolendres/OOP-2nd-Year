/* ------------------------------------------------------
Final project Milestone 2
Module: Status
Filename: Status.cpp
Version 1.0
Author: Francis Lloyd Colendres  2022-03-12
Revision History
-----------------------------------------------------------
Date          Reason
03/11         Redefined operator <<
03/31         Updated copy constructor
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "Status.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   Status::Status(const char* c)
   {
      ut.alocpy(m_errDesc, c);
      m_errCode = 0;
   }

   Status::Status(const Status& s)
   {
      operator=(s);
   }

   Status& Status::operator=(const Status& s)
   {
      if (this != &s)
      {
         m_errCode = s.m_errCode;
         if (s.m_errDesc != nullptr)
         {
            ut.alocpy(m_errDesc, s.m_errDesc);
         }
      }
      return *this;
   }

   Status::~Status()
   {
      clear();
   }

   Status& Status::operator=(int num)
   {
      m_errCode = num;
      return *this;
   }

   Status& Status::operator=(const char* str)
   {
      ut.alocpy(m_errDesc, str);
      return *this;
   }

   Status::operator int()const
   {
      return m_errCode;
   }

   Status::operator const char* () const
   {
      return m_errDesc;
   }

   Status::operator bool() const
   {
      return m_errDesc == nullptr;
   }

   Status& Status::clear()
   {
      delete[] m_errDesc;
      m_errDesc = nullptr;
      m_errCode = 0;
      return *this;
   }

   ostream& operator<<(ostream& ostr, const Status& s)
   {
      if (!s)
      {
         if (int(s) != 0)
         {
            ostr << "ERR#" << int(s) << ": " << (const char*)s;
         }
         else
         {
            ostr << (const char*)s;
         }
      }
      return ostr;
   }

}
