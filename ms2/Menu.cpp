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

#include <iostream>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
   Menu::Menu()
   {
      m_options = nullptr;
      m_numOptions = 0;
   }
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
         ut.strcpy(m_options, options);
         m_numOptions = numOptions;
      }
   }

   Menu::Menu(const Menu& M)
   {
      m_numOptions = M.m_numOptions;
      if (M.m_numOptions <= 15 || M.m_options != nullptr)
      {
         m_options = new char(ut.strlen(M.m_options) + 1);
         ut.strcpy(m_options, M.m_options);
      }
      else
         m_options = nullptr;
   }

   Menu& Menu::operator=(const Menu& M)
   {
      if (this != &M)
      {
         m_numOptions = M.m_numOptions;
         if (M.m_numOptions < 15 || M.m_options != nullptr)
         {
            m_options = new char(ut.strlen(M.m_options) + 1);
            ut.strcpy(m_options, M.m_options);
         }
         else
            m_options = nullptr;
      }
      return *this;
   }

   Menu::~Menu()
   {
      delete[] m_options;
   }

   unsigned int Menu::run() const
   {
      bool invalid = true;
      int val = 0;
      cout << m_options << "0- Exit" << endl;
      cout << "> ";
      do
      {
         cin >> val;
         if (!cin)
         {
            cout << "Invalid Integer, retry: ";
         }
         else if (val < 0 || (unsigned int)val > m_numOptions)
         {
            cout << "Value out of range [0<=val<=" << m_numOptions << "]: ";
         }
         else
            invalid = false;
      } while (invalid);
      return val;
   }

}