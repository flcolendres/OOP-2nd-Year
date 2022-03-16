/* ------------------------------------------------------
Final project Milestone 2
Module: AidMan
Filename: AidMan.cpp
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
#include "AidMan.h"
#include "Date.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
   unsigned int AidMan::menu() const
   {
      cout << "Aid Management System Version 0.1" << endl <<
         "Date: " << Date() << endl <<
         "Data file:  " << (m_fileName == nullptr ? "No file" : m_fileName) << endl <<
         "---------------------------------\n";

      return m_mainMenu.run();
   }

   AidMan::AidMan()
   {

   }

   AidMan::~AidMan()
   {
      delete[] m_fileName;
   }

   void AidMan::run()
   {
      int val = 999;
      do
      {
         val = menu();
         switch (val)
         {
         case 1:
            cout << endl << "****List Items****\n\n";
            break;
         case 2:
            cout << endl << "****Add Item****\n\n";
            break;
         case 3:
            cout << endl << "****Remove Item****\n\n";
            break;
         case 4:
            cout << endl << "****Update Quantity****\n\n";
            break;
         case 5:
            cout << endl << "****Sort****\n\n";
            break;
         case 6:
            cout << endl << "****Ship Items****\n\n";
            break;
         case 7:
            cout << endl << "****New/Open Aid Database****\n\n";
            break;
         default:
            cout << "Exiting Program!" << endl;
         }
      } while (val);
   }

}