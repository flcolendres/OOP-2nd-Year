/* ------------------------------------------------------
Final project Milestone 2
Module: Item
Filename: item.cpp
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
#include "Item.h"
#include "Utils.h"
namespace sdds 
{
   Item::Item()
   {
      m_price = m_qty = m_qtyNeeded = m_linear = m_sku = 0;
   }
   Item::Item(const Item& I)
   {
      m_price = I.m_price;
      m_qty = I.m_qty;
      m_qtyNeeded = I.m_qtyNeeded;
      ut.alocpy(m_desc, I.m_desc);
      m_linear = I.m_linear;
      m_state = I.m_state;
      m_sku = I.m_sku;
   }
   Item& Item::operator=(const Item& I)
   {
      if (this != &I)
      {
         m_price = I.m_price;
         m_qty = I.m_qty;
         m_qtyNeeded = I.m_qtyNeeded;
         ut.alocpy(m_desc, I.m_desc);
         m_linear = I.m_linear;
         m_state = I.m_state;
         m_sku = I.m_sku;
      }
      return *this;
   }
   Item::~Item()
   {
      delete[] m_desc;
      m_desc = nullptr;
   }
}