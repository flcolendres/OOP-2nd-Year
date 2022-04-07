/* ------------------------------------------------------
Final project Milestone 5
Module: AidMan
Filename: AidMan.h
Version 1.0
Author: Francis Lloyd Colendres  2022-03-12
Revision History
-----------------------------------------------------------
Date          Reason
04-06         Changed the way m_iproduct is initialized to safe empty state
04-06         Functions that call an option are set to private.
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
      iProduct* m_iproduct[sdds_max_num_items]{};
      int m_numOfIproduct;
      void listItem();
      void addItem();
      void removeItem();
      void updateItem();
      void sortItem();
      void shipItem();
      void itemDesc(char* input);
   public:
      AidMan();
      AidMan(const AidMan& a) = delete;
      AidMan& operator=(const AidMan& A) = delete;
      virtual ~AidMan();
      void run();
      void save();
      void deallocate();
      void load();
      void remove(int index);
      int list(const char* sub_desc = nullptr);
      int search(int sku) const;
   };
}
#endif