/* ------------------------------------------------------
Final project Milestone 1
Module: Status
Filename: Status.cpp
Version 1.0
Author: Francis Lloyd Colendres  2022-03-08
Revision History
-----------------------------------------------------------
Date          Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "Status.h"
#include "Utils.h"
namespace sdds {
   Status::Status(const char* c)
   {
      ut.alocpy(m_errDesc, c);
      m_errCode = 0;
   }

   Status::Status(const Status& s)
   {
      if (s.m_errDesc != nullptr)
      {
         ut.alocpy(m_errDesc, s.m_errDesc);
         m_errCode = s.m_errCode;
      }
   }

   Status& Status::operator=(const Status& s)
   {
      if (this != &s)
      {
         if (s.m_errDesc != nullptr)
         {
            ut.alocpy(m_errDesc, s.m_errDesc);
            m_errCode = s.m_errCode;
         }
      }
      return *this;
   }

   Status::~Status()
   {
      delete[] m_errDesc;
   }

}
