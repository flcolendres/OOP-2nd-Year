/* ------------------------------------------------------
Final project Milestone 1
Module: Date
Filename: Date.h
Version 1.0
Author: Francis Lloyd Colendres  2022-03-08
Revision History
-----------------------------------------------------------
Date          Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Status.h"
namespace sdds
{
   class Date 
   {
      const int m_maxyear = 2030;
      int m_year;
      int m_month;
      int m_day;
      Status m_state;
      bool m_format;
      bool validate();
      int uniqueDateVal();
   public:
      Date(const int year = 0, const int month = 0, const int date = 0);
      Date& operator==(const Date& d)const;
      Date& operator!=(const Date& d)const;
      Date& operator<(const Date& d)const;
      Date& operator>(const Date& d)const;
      Date& operator<=(const Date& d)const;
      Date& operator>=(const Date& d)const;
      const Status& state()const;
      Date& formatted();
      std::ostream& write(std::ostream& ostr);
      std::istream& read(std::istream& istr);
   };
   std::ostream& operator<<(std::ostream& ostr, Date& d);
   std::istream& operator>>(std::istream& istr, Date& d);

}
#endif