#include "Utils.h"
/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Mar. 3, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

namespace sdds
{
    bool isEmpty(char* input)
    {
        return !strcmp(input, "") || !strcmp(input, " ");
    }
}