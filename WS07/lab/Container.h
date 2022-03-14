/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 27, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include <iostream>
namespace sdds
{
   class Container
   {
      char m_content[50];
      int m_capacity;
      int m_containerVol;
   public:
      Container();
      Container(const char* content, int capacity, int containerVol = 0);
      int operator+=(int val);
      int operator-=(int val);
      operator bool();
      Container& clear(int capacity, const char* content);
      std::ostream& print(std::ostream& ostr) const;
      std::istream& read(std::istream& istr);
   protected:
      Container& setEmpty();
      int capacity();
      int volume();
   };
   std::ostream& operator<<(std::ostream& ostr, Container& c);
   std::istream& operator>>(std::istream& istr, Container& c);
}
#endif