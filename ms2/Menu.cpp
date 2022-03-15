/* ------------------------------------------------------
Final project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0
Author: Francis Lloyd Colendres  2022-03-12
Revision History
-----------------------------------------------------------
Date          Reason

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Menu.h"
#include "Utils.h"
namespace sdds
{
   Menu::Menu(unsigned int numOptions, const char* options)
   {
      if (numOptions > 15 || options == nullptr)
      {
         m_options = nullptr;
         m_numOptions = 0;
      }
      else
      {
         m_options = new char(ut.strlen(options) + 1);
         m_numOptions = numOptions;
      }
   }

}