/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 14, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include <iostream>
#include "Container.h"
namespace sdds 
{
   class Pack : public Container 
   {
      int m_unitSize;
   public:
      Pack(const char* content, int size, int unitSize = 330, int numUnits = 0);
      int operator+=(int val);
      int operator-=(int val);
      int unit();
      int noOfUnits();
      int size();
      Pack& clear(int packSize, int unitSize, const char* content);
      std::ostream& print(std::ostream& ostr);
      std::istream& read(std::istream& istr);
   };
   std::ostream& operator<<(std::ostream& ostr, Pack& p);
   std::istream& operator>>(std::istream& istr, Pack& p);

}

#endif