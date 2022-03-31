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
#include <fstream>
#include "Perishable.h"
#include "Utils.h"
using namespace std;
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

   int Perishable::readSku(std::istream& istr)
   {
      return ut.getint(10000, 39999, "SKU: ");
   }

   std::ofstream& Perishable::save(std::ofstream& ofstr) const
   {
      Date D;
      if (*this)
      {
         //it will call the save of the Base class.
         Item::save(ofstr);
         //   writes a tab
         ofstr << "\t";
         //   writes the handling instructions, if handling instructions existand the attribute is not empty.
         if (m_instruction && m_instruction[0] != ' ') ofstr << m_instruction;
         //   writes a tab
         ofstr << "\t";
         //   writes an unformatted copy of the expiry date
         D = m_expiry;
         D.formatted(false);
         ofstr << D;
      }
      return ofstr;
   }
   std::ifstream& Perishable::load(std::ifstream& ifstr)
   {
      char temp[1000];
      //calls the load of the Base class.
      Item::load(ifstr);
      //reads the handling instructions dynamically into the handling instructions attribute
      ifstr.getline(temp, 1000, '\t');
      ut.alocpy(m_instruction, temp);
      //ignores the tab
      ifstr.ignore(1000, '\t');
      //reads the expiry date
      m_expiry.Date::read(ifstr);
      //ignores the newline.
      ifstr.ignore(1000, '\n');
      //if the ifstream object has failed, it will set the state of the Item 
      //to "Input file stream read (perishable) failed!"
      if (ifstr.fail()) Item::m_state = "Input file stream read (perishable) failed!";
      return ifstr;
   }
   std::ostream& Perishable::display(std::ostream& ostr) const
   {
      if (*this)
         ostr << m_state;
      else if (linear())
      {
         Item::display(ostr);
         if (m_instruction && m_instruction[0] != ' ')
            ostr << "*";
         else
            ostr << " ";
         ostr << m_expiry;
      }
      else if (!linear())
      {
         ostr << "Perishable ";
         Item::display(ostr);
         ostr << "Expiry date: ";
         ostr << m_expiry;
         if (m_instruction && m_instruction[0] != ' ')
         {
            ostr << "Handling Instructions: ";
            ostr << m_instruction;
         }
         ostr << "\n";
      }
      return ostr;
   }
   std::istream& Perishable::read(std::istream& istr)
   {
      char temp[1000];
      Item::read(istr);
      delete[] m_instruction;
      m_instruction = nullptr;
      cout << "Expiry date (YYMMDD): ";
      m_expiry.Date::read(istr);
      istr.ignore(1000, '\n');
      cout << "Handling Instructions, ENTER to skip: ";
      if (istr.peek() != '\n')
      {
         istr >> temp;
         ut.alocpy(m_instruction, temp);
      }
      if (istr.fail())
      {
         m_state = "Perishable console date entry failed!";
      }
      return istr;
   }
}