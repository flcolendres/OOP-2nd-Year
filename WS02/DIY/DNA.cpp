/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Jan. 23, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "DNA.h"

using namespace std;
namespace sdds
{
	DNAStrand* dnaFile;
	DNAStrand* dnaMatch;
	int numOfDna;
	int dnaArrSize;
	int allSize;

	bool beginSearch(const char* filename)
	{
		int i = 0;
		bool result = false;
		FILE* fp = fopen(filename, "r");
		if (fp)
		{
			initialize(2);
			do
			{
				if (numOfDna == dnaArrSize)
				{
					DNAStrand* temp = new DNAStrand[dnaArrSize + allSize];
					for (i = 0; i < numOfDna; i++)
					{
						temp[i] = dnaFile[i];
					}
					delete[] dnaFile;
					dnaFile = temp;
					dnaArrSize += allSize;
				}

				if (!feof(fp))
				{
					fscanf(fp, "%d,%s\n", &dnaFile[numOfDna].id, &dnaFile[numOfDna].dna);
					numOfDna++;
				}
				else
				{
					result = true;
				}
				
				

			} while (!result);

			fflush(fp);
			fclose(fp);
		
		}
		return result;
	}
	bool read(const char* subDNA)
	{
		bool result = false;





		return result;
	}
	void sort()
	{
	}
	void displayMatches()
	{
	}
	void deallocate()
	{
	}
	void endSearch()
	{
	}
	void initialize(int allocSize)
	{
		numOfDna = 0;
		dnaArrSize = allSize = allocSize;
		dnaFile = new DNAStrand[allSize];
	}

}