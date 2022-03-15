/* ------------------------------------------------------
Final project Milestone 2
Module: Aidman
Filename: Aidman.h
Version 1.0
Author: Francis Lloyd Colendres  2022-03-12
Revision History
-----------------------------------------------------------
Date          Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
namespace sdds
{
   class Aidman
   {
      char* m_fileName;
      Menu m_Menu;
      unsigned int menu();
   public:
      Aidman(unsigned int numOptions, const char* options);
      Aidman(const Aidman& A);
      Aidman& operator=(const Aidman& A);
      virtual ~Aidman();
      void run();

   };
}
#endif