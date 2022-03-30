/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 27, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include "Text.h"
namespace sdds 
{
   class HtmlText : public Text 
   {
      char* m_title{};
   public:
      HtmlText(const char* title = nullptr);
      HtmlText(const HtmlText& ht);
      HtmlText& operator=(const HtmlText& ht);
      virtual ~HtmlText();
      std::ostream& write(std::ostream& ostr) const;
   };
}
#endif