/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 21, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds
{
   ostream& operator<<(ostream& ostr, Shape& s)
   {
      s.draw(ostr);
      return ostr;
   }
   istream& operator>>(istream& istr, Shape& s)
   {
      s.getSpecs(istr);
      return istr;
   }
   Shape::~Shape()
   {

   }
}