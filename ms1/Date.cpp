/* ------------------------------------------------------
Final project Milestone 1
Module: Date
Filename: Date.cpp
Version 1.0
Author: Francis Lloyd Colendres  2022-03-08
Revision History
-----------------------------------------------------------
Date          Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Date.h"
#include "Utils.h"
namespace sdds
{
   bool Date::validate()
   {
      bool result = false;
      int year;
      ut.getSystemDate(&year, nullptr, nullptr);
      if (m_year < year || m_year > m_maxyear)
      {
         m_state = "Invalid year in date";
         m_state = 1;
      }
      else if(m_month < 1 || m_month > 12)
      {
         m_state = "Invalid month in date";
         m_state = 2;   
      }
      else if (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year))
      {
         m_state = "Invalid day in date";
         m_state = 3;
      }
      else
      {
         result = true;
      }
      return result;
   }
   int Date::uniqueDateVal()
   {
      return m_year * 372 + m_month * 31 + m_day;
   }
   Date::Date(const int year, const int month, const int date)
   {
      if (year == month == date)
      {
         ut.getSystemDate(&m_year, &m_month, &m_day);
      }
      else
      {
         m_year = year;
         m_month = month;
         m_day = date;
         validate();
      }
   }
}