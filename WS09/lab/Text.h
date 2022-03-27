/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 27, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <iostream>
namespace sdds 
{
   class Text
   {
      char* m_content;
   public:
      Text();
      Text(const Text& T);
      Text& operator=(const Text& T);
      virtual ~Text();
      std::istream& read(std::istream& istr);
      int getFileLength(std::istream& is);
      virtual std::ostream& write(std::ostream& ostr) const;
   protected:
      const char& operator[](int index)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Text& T);
   std::istream& operator>>(std::istream& istr, Text& T);
}
#endif