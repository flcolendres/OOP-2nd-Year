/* ------------------------------------------------------
Final project Milestone 2
Module: Aidman
Filename: Aidman.cpp
Version 1.0
Author: Francis Lloyd Colendres  2022-03-12
Revision History
-----------------------------------------------------------
Date          Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include "Aidman.h"
#include "Date.h"
using namespace std;
namespace sdds
{
   unsigned int Aidman::menu()
   {
      if (m_fileName != nullptr)
      {
         cout << "Aid Management System Version 0.1" << endl << 
            "Date: " << Date() << endl <<
            "Data file:  " << m_fileName << endl <<
            "---------------------------------\n";
      }
      else
      {
         cout << "No file" << endl;
      }
      return 0;
   }

   Aidman::Aidman(unsigned int numOptions, const char* options)
   {

   }

}