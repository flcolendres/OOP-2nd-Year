/* ------------------------------------------------------
Final project Milestone 4
Module: Perishable
Filename: Perishable.cpp
Version 1.0
Author: Francis Lloyd Colendres  2022-03-31
Revision History
-----------------------------------------------------------
Date          Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "Perishable.h"
#include "Utils.h"

namespace sdds
{
   Perishable::Perishable() : Item()
   {
      m_expiry = Date();
      m_instruction = nullptr;
   }

   Perishable::Perishable(const Perishable& P)
   {
      operator=(P);
   }

   Perishable& Perishable::operator=(const Perishable& P)
   {
      if (this != &P)
      {
         m_expiry = P.m_expiry;
         ut.alocpy(m_instruction, P.m_instruction);
      }
      return *this;
   }

   Perishable::~Perishable()
   {
      delete[] m_instruction;
   }

   const Date& Perishable::expiry()
   {
      return m_expiry;
   }

}