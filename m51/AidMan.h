/* ------------------------------------------------------
Final project Milestone 51
Module: AidMan
Filename: AidMan.h
Version 1.0
Author: Francis Lloyd Colendres  2022-03-12
Revision History
-----------------------------------------------------------
Date          Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_AidMan_H
#define SDDS_AidMan_H
#include "Menu.h"
#include "iProduct.h"
namespace sdds
{
   const int sdds_max_num_items = 100;
   class AidMan
   {
      char* m_fileName;
      Menu m_mainMenu;
      unsigned int menu() const;
      iProduct* m_iproduct[sdds_max_num_items] = { 0 };
      int m_numOfIproduct;
   public:
      AidMan();
      AidMan(const AidMan& a) = delete;
      AidMan& operator=(const AidMan& A) = delete;
      virtual ~AidMan();
      void run();
      void save();
   };
}
#endif