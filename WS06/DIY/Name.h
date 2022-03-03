/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Feb. 27, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_NAME_H
#define SDDS_NAME_H
namespace sdds
{
   class Name
   {
      char* m_nameFirst;
      char* m_nameMiddle;
      char* m_nameLast;
   public:
      Name();
      Name(char* first);
      Name(char* first, char* last);
      Name(char* first, char* middle, char* last);
      Name(const Name& n);
      Name& operator=(const Name& n);
      ~Name();
   };
}
#endif