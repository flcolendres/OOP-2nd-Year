/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 21, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include <iostream>
#include "LblShape.h"
namespace sdds
{
   class Line : public LblShape
   {
      int m_length;
   public:
      Line();
      Line(const char* cstr, int length);
      void getSpecs(std::istream& istr);
      void draw(std::ostream& ostr) const;
   };

}
#endif