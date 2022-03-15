/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 14, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <cstring>
#include "Pack.h"
using namespace std;
namespace sdds
{
   Pack::Pack(const char* content, int size, int unitSize, int numUnits) : Container(content, size* unitSize, numUnits* unitSize)
   {
      if (unitSize > 0)
         m_unitSize = unitSize;
      else
      {
         setEmpty();
         m_unitSize = 0;
      }
   }
   int Pack::operator+=(int val)
   {
      return Container::operator+=(val * m_unitSize) / m_unitSize;
   }

   int Pack::operator-=(int val)
   {
      return Container::operator-=(val * m_unitSize) / m_unitSize;
   }

   int Pack::unit()
   {
      return m_unitSize;
   }

   int Pack::noOfUnits()
   {
      return volume() / m_unitSize;
   }

   int Pack::size()
   {
      return Container::capacity() / m_unitSize;
   }

   Pack& Pack::clear(int packSize, int unitSize, const char* content)
   {
      if (unitSize > 0)
      {
         Container::clear(packSize * unitSize, content);
         m_unitSize = unitSize;
      }
      return *this;
   }

   ostream& Pack::print(ostream& ostr)
   {
      Container::print(ostr);
      ostr << ", " << noOfUnits() << " in a pack of " << size();
      return ostr;
   }

   istream& Pack::read(istream& istr)
   {
      int val = 0;
      bool invalid = true;
      if (*this)
      {
         if (volume() < capacity())
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
               else if (val < 0 || val > size() - noOfUnits())
               {
                  cout << "Value out of range [1<=val<=" << size() - noOfUnits() << "]: ";
               }
               else
               {
                  invalid = false;
               }
            } while (invalid);
            cout << "Added " << (*this += val) << endl;
         }
         else
         {
            cout << "Pack is full!, press <ENTER> to continue...";
            istr.ignore();
            istr.get();
         }
      }
      else
      {
         cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
         istr.get();
      }
      return istr;
   }


   std::ostream& operator<<(std::ostream& ostr, Pack& p)
   {
      return p.print(ostr);
   }

   std::istream& operator>>(std::istream& istr, Pack& p)
   {
      return p.read(istr);
   }

}