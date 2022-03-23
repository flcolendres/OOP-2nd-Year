/* ------------------------------------------------------
Final project Milestone 2
Module: iProduct
Filename: iProduct.h
Version 1.0
Author: Francis Lloyd Colendres  2022-03-22
Revision History
-----------------------------------------------------------
Date          Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "iProduct.h"
namespace sdds
{
   std::ostream& operator<<(std::ostream& ostr, iProduct& ip)
   {
      ip.display(ostr);
      return ostr;
   }
   std::istream& operator>>(std::istream& istr, iProduct& ip)
   {
      ip.read(istr);
      return istr;
   }
   iProduct::~iProduct() 
   {

   }
}