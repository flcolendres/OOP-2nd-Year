/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 3, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <cstring>
#include "Utils.h"
namespace sdds
{
    bool isEmpty(const char* input)
    {
       bool result = false;
       if (!strcmp(input, "") || !strcmp(input, " ") || !strcmp(input, "   "))
          result = true;
        return result;
    }
}