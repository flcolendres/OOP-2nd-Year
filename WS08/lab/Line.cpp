/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 21, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "Line.h"
using namespace std;
namespace sdds
{
   Line::Line() : LblShape()
   {
      m_length = 0;
   }
   Line::Line(const char* cstr, int length) : LblShape(cstr)
   {
      m_length = length;
   }
   void Line::getSpecs(istream& istr)
   {
      LblShape::getSpecs(istr);
      istr >> m_length;
      istr.ignore('\n');
   }
   void Line::draw(ostream& ostr) const
   {
      int i;
      if (m_length > 0 && label())
      {
         ostr << label() << endl;
         for (i = 0; i <= m_length; i++) ostr << "=";
      }
   }
}