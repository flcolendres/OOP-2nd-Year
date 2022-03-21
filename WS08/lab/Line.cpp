/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 21, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "Line.h"

namespace sdds
{
   Shape::Shape() : LblShape()
   {
      m_length = 0;
   }
   Shape::Shape(const char* cstr, int length)
   {
   }
   void Shape::getSpecs(std::istream& istr)
   {
   }
   void Shape::draw(std::ostream& ostr) const
   {
   }
}