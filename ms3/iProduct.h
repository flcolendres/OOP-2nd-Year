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
#ifndef SDDS_IPRODUCT_H
#define SDDS_IPRODUCT_H
#include <iostream>
namespace sdds
{
   class iProduct
   {
      int readSku(std::istream& istr);
      // to reduce the quantity on hand
      int operator-=(int qty);
      // to increase the quantity on hand
      int operator+=(int qty);
      // returns the price of the produce
      operator double()const;
      // returns if the iProduct is in a good state
      operator bool()const;
      // returns the number of products needed
      int qtyNeeded()const;
      // retuns the quantity on hand
      int qty()const;
      // determines if the iProduct is displayed in a linear format or 
      // descriptive format
      void Linear(bool isLinear);
      // saves the iProduct into a file
      std::ofstream& save(std::ofstream& ofstr)const;
      // loads an iProduct from a file
      std::ifstream& load(std::ifstream& ifstr);
      // displays the iProduct on the screen
      std::ostream& display(std::ostream& ostr)const;
      // reads the iProduct from the console
      std::istream& read(std::istream& istr);
      // return true if the sku is a match to the iProduct's sku
      bool operator==(int sku)const;
      // rtrns true if the description is found in the iPorduct's description
      bool operator==(const char* description)const;

   };
}
#endif