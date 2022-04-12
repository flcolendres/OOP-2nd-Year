/*------------------------------------------------------
Workshop 10 part 1
Module: Temps
Version 1.0
Author : Francis Colendres 04/11/2022
Revision History
-----------------------------------------------------------
Date       Reason
----------------------------------------------------------- */

#ifndef SDDS_TEMPS_H
#define SDDS_TEMPS_H
#include <iostream>
#include "Collection.h"
namespace sdds
{
   /*
   * Typename Type
   * Type must be able to work with operator ==
   * Type needs to have default constructor
   * Type needs to handle copy assignment
   */
   template <typename Type>
   Collection<Type> select(const Type objArr[], int size, const Type& objRef)
   {
      unsigned int count = 0;
      for (int i = 0; i < size; i++)
      {
         if (objArr[i] == objRef)
            count++;
      }
      Collection<Type> coll(count);

      for (int i = 0, j = 0; i < size; i++)
      {
         if (objArr[i] == objRef)
         {
            coll[j] = objArr[i];
            j++;
         }
      }
      return coll;
   }
   /*
   * Typename T
   * Must be able to handle insertion operator
   * Type must have a size query function
   */
   template <typename T>
   void printCollection(const Collection<T>& objRef, const char* cStr)
   {
      std::cout << cStr << "\n";
      for (unsigned int i = 0; i < objRef.size(); i++)
         std::cout << objRef[i] << "\n";
   }
}


#endif
