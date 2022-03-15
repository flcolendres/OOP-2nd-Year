/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 14, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Container.h"
using namespace std;
namespace sdds
{
   Container::Container()
   {
      strcpy(m_content, "\0");
      m_capacity = 0;
      m_containerVol = 0;
   }
   Container::Container(const char* content, int capacity, int containerVol)
   {
      if (!strcmp(content, "\0") || containerVol > capacity)
      {
         strcpy(m_content, "\0");
         m_capacity = 0;
         m_containerVol = 0;
      }
      else
      {
         strcpy(m_content, content);
         m_capacity = capacity;
         m_containerVol = containerVol;
      }
   }
   int Container::operator+=(int val)
   {
      int addedVol = 0;
      while (m_containerVol < m_capacity && val > 0)
      {
         m_containerVol++;
         val--;
         addedVol++;
      }
      return addedVol;
   }
   int Container::operator-=(int val)
   {
      int subtractedVol = 0;
      while (m_containerVol > 0 && subtractedVol < val)
      {
         m_containerVol--;
         subtractedVol++;
      }
      return subtractedVol;
   }
   Container::operator bool()
   {
      return m_containerVol <= m_capacity && m_capacity > 0;
   }
   Container& Container::clear(int capacity, const char* content)
   {
      if (capacity > 0 && content != nullptr)
      {
         m_capacity = capacity;
         strcpy(m_content, content);
      }
      return *this;
   }
   ostream& Container::print(ostream& ostr) const
   {
      if (m_containerVol <= m_capacity && m_capacity > 0)
      {
      ostr << m_content << ": " << "(" <<
         m_containerVol << "cc/" << m_capacity << ")";
      }
      else
      {
         ostr << "****: (**cc/***)";
      }
      return ostr;
   }
   istream& Container::read(istream& istr)
   {
      bool invalid = true;
      int val = 0;
      if (*this)
      {
         cout << "Add to ";
         print(cout);
         cout << "\n> ";
         do
         {
            istr >> val;
            if (!istr)
            {
               cout << "Invalid Integer, retry: ";
            }
            else if(val < 0 || val > m_capacity)
            {
               cout << "Value out of range[1<=val<=" << m_capacity - m_containerVol << "]: ";
            }
            else
            {
               invalid = false;
            }
         } while (invalid);
         cout << "Added " << (*this += val) << " CCs" << endl;
      }
      else
      {
         cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
         istr.ignore();
         istr.get();
      }
      return istr;
   }
   Container& Container::setEmpty()
   {
      m_capacity = m_containerVol = 0;
      return *this;
   }
   int Container::capacity()
   {
      return m_capacity;
   }
   int Container::volume()
   {
      return m_containerVol;
   }
   std::ostream& operator<<(std::ostream& ostr, Container& c)
   {
      return c.print(ostr);
   }
   std::istream& operator>>(std::istream& istr, Container& c)
   {
      return c.read(istr);
   }
}