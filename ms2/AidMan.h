/* ------------------------------------------------------
Final project Milestone 2
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
namespace sdds
{
   class AidMan
   {
      char* m_fileName;
      Menu m_mainMenu;
      unsigned int menu() const;
   public:
      AidMan();
      AidMan(const AidMan& a) = delete;
      AidMan& operator=(const AidMan& A) = delete;
      virtual ~AidMan();
      void run();

   };
}
#endif