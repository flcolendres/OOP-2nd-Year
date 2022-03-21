/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 21, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>
#include "Shape.h"
namespace sdds
{
   class LblShape : public Shape 
   {
      char* m_label{};
   protected:
      char* label() const;
   public:
      LblShape();
      LblShape(const char* cstr);
      void getSpecs(std::istream& istr);
      virtual ~LblShape();
   };
}
#endif