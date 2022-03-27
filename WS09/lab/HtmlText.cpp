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

   }
}