/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 21, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include <iostream>
#include "LblShape.h"
namespace sdds
{
   class Rectangle : public LblShape 
   {
      int m_width;
      int m_height;
   public:
      Rectangle();
      Rectangle(const char* cstr, int width, int height);
      void getSpecs(std::istream& istr);
      void draw(std::ostream& ostr) const;
   };
}
#endif