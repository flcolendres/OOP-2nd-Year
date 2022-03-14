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
   Pack::Pack(const char* content, int size, int unitSize, int numUnits) : Container(content, size* unitSize, numUnits* unitSize)
   {
      if (unitSize > 0)
         m_unitSize = unitSize;
      else
      {
         setEmpty();
         m_unitSize = 0;
      }
   }
   int Pack::operator+=(int val)
   {
      return Container::operator+=(val * m_unitSize) / m_unitSize;
   }

   int Pack::operator-=(int val)
   {
      return Container::operator-=(val * m_unitSize) / m_unitSize;
   }

   int Pack::unit()
   {
      return m_unitSize;
   }

   int Pack::noOfUnits()
   {
      return Container::volume() / m_unitSize;
   }

   int Pack::size()
   {
      return Container::capacity() / m_unitSize;
   }

   Pack& Pack::clear(int packSize, int unitSize, const char* content)
   {
      if (unitSize > 0)
      {
         Container::clear(packSize, content);
         m_unitSize = unitSize;
      }
      return *this;
   }

   std::ostream& Pack::print(std::ostream& ostr)
   {
      Container::print(ostr);
      if (*this)
      {
         ostr << ", " << Container::capacity() << " in a pack of " << m_unitSize;
      }
      return ostr;
   }

}