/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 3, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>
#include <string>
namespace sdds
{
   class Name
   {
      char* m_nameFirst{};
      char* m_nameMiddle{};
      char* m_nameLast{};
   public:
      Name();
      Name(const char* first);
      Name(const char* first, const char* last);
      Name(const char* first, const char* middle, const char* last);
      Name(const Name& n);
      Name& operator=(const Name& n);
      ~Name();
      void setShort(bool valid);
      Name& operator+=(const char* input);
      operator bool() const;
      std::ostream& print(std::ostream& ostr) const;
      std::istream& read(std::istream& istr);
      void dealloc();
   };
   std::ostream& operator<<(std::ostream& ostr, const Name& n);
   std::istream& operator>>(std::istream& istr, Name& n);

}
#endif