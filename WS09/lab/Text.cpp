/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 27, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Text.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds
{
   Text::Text()
   {
   }
   Text::Text(const Text& T)
   {
      operator=(T);
   }
   Text& Text::operator=(const Text& T)
   {
      if (this != &T)
      {
         delete[] m_content;
         m_content = new char[strlen(T.m_content) + 1];
         strcpy(m_content, T.m_content);
      }
      return *this;
   }
   Text::~Text()
   {
      delete[] m_content;
   }
   std::istream& Text::read(std::istream& istr)
   {
      int i;
      int length = getFileLength(istr);
      delete[] m_content;
      m_content = new char[length + 1];
      for (i = 0; i < length - 1; i++)
      {
         m_content[i] = istr.get();
         istr.clear();
      }
      if (i) m_content[i] = '\0';
      return istr;
   }
   int Text::getFileLength(std::istream& is)
   {
      int len{};
      if (is) {
         // save the current read position
         std::streampos cur = is.tellg();
         // go to the end
         is.seekg(0, ios::end);
         // let what is the positions (end position = size)
         len = is.tellg();
         // now go back to where you were.
         is.seekg(cur);
      }
      return len;
   }
   std::ostream& Text::write(std::ostream& ostr) const
   {
      if (m_content)
      {
         ostr << m_content;
      }
      return ostr;
   }
   const char& Text::operator[](int index) const
   {
      char c = '\0';
      if (m_content[index] > 0)
      {
         if (index <= (int)strlen(m_content) - 1)
         {
            c = m_content[index];
         }
      }
      return c;
   }
   std::ostream& operator<<(std::ostream& ostr, const Text& T)
   {
      return T.write(ostr);
   }
   std::istream& operator>>(std::istream& istr, Text& T)
   {
      return T.read(istr);
   }
}