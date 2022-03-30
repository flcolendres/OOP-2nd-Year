/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 27, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HtmlText.h"
using namespace std;
namespace sdds
{
   HtmlText::HtmlText(const char* title) : Text()
   {
      if (title)
      {
         m_title = new char[strlen(title) + 1];
         strcpy(m_title, title);
      }
      else
         m_title = nullptr;
   }
   HtmlText::HtmlText(const HtmlText& ht)
   {
      Text::operator=(ht);
      operator=(ht);
   }
   HtmlText& HtmlText::operator=(const HtmlText& ht)
   {
      if (this != &ht)
      {
         Text::operator=(ht);
         delete[] m_title;
         m_title = new char[strlen(ht.m_title) + 1];
         strcpy(m_title, ht.m_title);
      }
      return *this;
   }
   HtmlText::~HtmlText()
   {
      delete[] m_title;
   }
   std::ostream& HtmlText::write(std::ostream& ostr) const
   {
      int i;
      bool MS = false;
      //ostr << "&lt;html&gt;&lt;head&gt;&lt;title&gt;";
      ostr << "<html><head><title>";
      if (m_title)
         ostr << m_title;
      else
         ostr << "No Title";
      /*ostr << "&lt;/title&gt;&lt;/head&gt;&lt;br /&gt;\n&lt;body&gt;&lt;br /&gt;\n";*/
      ostr << "</title></head>\n<body>\n";
      if (m_title)
         ostr << "<h1>" << m_title << "</h1>\n";
      /*ostr << "&lt;h1&gt;" << m_title << "&lt;/h1&gt;";*/

      for (i = 0; operator[](i) > 0; i++)
      {
         if (operator[](i) == ' ')
         {
            if (MS)
               ostr << "&nbsp;";
            else
            {
               MS = true;
               ostr << ' ';
            }
         }
         else if (operator[](i) == '<')
         {
            ostr << "&lt;";
            MS = false;
         }
         else if (operator[](i) == '>')
         {
            ostr << "&gt;";
            MS = false;
         }
         else if (operator[](i) == '\n')
         {
            ostr << "<br />\n";
            MS = false;
         }
         else
         {
            MS = false;
            ostr << operator[](i);
         }
      }
      ostr << "</body>\n</html>";
      return ostr;
   }
}