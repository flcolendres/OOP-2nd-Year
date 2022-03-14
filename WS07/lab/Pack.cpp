/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 27, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <cstring>
#include "Pack.h"

namespace sdds
{
   Pack::Pack(const char* content, int size, int unitSize, int numUnits) : Container(content, size * unitSize, numUnits * unitSize)
   {
      if (unitSize > 0)
         m_unitSize = unitSize;
      else
      {
         setEmpty();
         m_unitSize = 0;
      }
   }
}