/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 21, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds
{
   Rectangle::Rectangle() : LblShape()
   {
      m_width = 0;
      m_height = 0;
   }

   Rectangle::Rectangle(const char* cstr, int width, int height) : LblShape(cstr)
   {
      m_width = width;
      m_height = height;
      if (m_height < 3 || m_width < ((int)strlen(label()) + 1))
      {
         m_width = 0;
         m_height = 0;
      }
   }

   void Rectangle::getSpecs(std::istream& istr)
   {
      LblShape::getSpecs(istr);
      istr >> m_width;
      istr.ignore('\n');
      istr >> m_height;
      istr.ignore('\n');
   }

   void Rectangle::draw(std::ostream& ostr) const
   {
      int i;
      if (m_width && m_height)
      {
         // first line
         ostr << "+";
         for (i = 0; i <= m_width - 2; i++) ostr << "-";
         ostr << "+" << endl;
         // second line
         ostr << "| ";
         ostr << label();
         for (i = 0; i <= m_width - 2; i++) ostr << " ";
         ostr << "|" << endl;
         // third line
         for (i = 0; i <= m_height - 3; i++)
         {
            ostr << "|";
            for (i = 0; i <= m_width - 2; i++) ostr << " ";
            ostr << "|" << endl;
         }
         // last line
         ostr << "+";
         for (i = 0; i <= m_width - 2; i++) ostr << "-";
         ostr << "+" << endl;
      }

   }

}