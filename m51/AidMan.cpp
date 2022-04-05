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
#include <fstream>
#include "AidMan.h"
#include "Date.h"
#include "Utils.h"
#include "Perishable.h"
using namespace std;
namespace sdds
{
   unsigned int AidMan::menu() const
   {
      cout << "Aid Management System Version 0.1" << endl <<
         "Date: " << Date() << endl <<
         "Data file: " << (m_fileName == nullptr ? "No file" : m_fileName) << endl <<
         "---------------------------------\n";
      return m_mainMenu.run();
   }

   AidMan::AidMan()
   {
      m_mainMenu.set(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n");
      m_fileName = nullptr;
      m_numOfIproduct = 0;
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
         if (val != 7 && m_fileName == nullptr) val = 7;
         switch (val)
         {
         case 0:
            cout << "Exiting Program!" << endl;
            save();
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
            cout << endl << "****New/Open Aid Database****\n";
            cout << "Enter file name: ";
            break;
         }
      } while (val);
   }

   void AidMan::save()
   {
      if (m_fileName)
      {
         ofstream ofstr(m_fileName);
         for (int i = 0; m_iproduct[i] != 0; i++)
            m_iproduct[i]->save(ofstr);
      }
   }

   void AidMan::deallocate()
   {

      delete[] *m_iproduct;
      m_numOfIproduct = 0;
   }

   void AidMan::load()
   {

      int i = 0;
      save();
      deallocate();
      ifstream ifstr(m_fileName);
      if (ifstr.fail())
      {
         cout << "Failed to open " << m_fileName << " for reading!" << endl <<
           "Would you like to create a new data file?" << endl <<
            "1- Yes!" << endl << 
            "0 - Exit" << endl << "> ";
         cin >> i;
         if (i)
            ofstream ofstr(m_fileName);
      }
      else
      {
         if (ifstr.peek())
         {
            if (Perishable::expiry() != nullptr)
            {

            }
         }
      }
   }

}