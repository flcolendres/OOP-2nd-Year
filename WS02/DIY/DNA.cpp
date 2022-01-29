/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Jan. 28, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "DNA.h"
#include "cStrTools.h"

using namespace std;
namespace sdds
{
	DNAStrand* dnaMatch;
	FILE* fp = NULL;
	int numOfDna;
	int dnaArrSize;
	int allSize;

	// Returns true if the file is opened successfully and returns false it fails to open the file.
	bool beginSearch(const char* filename)
	{
		bool result = false;

		if (fp = fopen(filename, "r"))
			result = true;

		return result;
	}
	// Returns true if at least one match is found and false if no match is found in the records.
	// creates an array of DNA records to the number of matches found in the file and stores the matches in them.
	bool read(const char* subDNA)
	{
		bool found = false;
		int id, i;
		char dna[1000 + 1];


		while (!feof(fp) && !found)
		{
			if (!feof(fp))
			{
				fscanf(fp, "%d,%s\n", &id, &dna);
				if (strStr(dna, subDNA))
				{
					found = true;
				}
			}
		}
		rewind(fp);

		if (found)
		{
			initialize(10);
			while (!feof(fp))
			{
				if (numOfDna == dnaArrSize)
				{
					DNAStrand* temp = new DNAStrand[dnaArrSize + allSize];
					for (i = 0; i < numOfDna; i++)
					{
						temp[i] = dnaMatch[i];
					}
					delete[] dnaMatch;
					dnaMatch = temp;
					dnaArrSize += allSize;
				}
				if (!feof(fp))
				{
					fscanf(fp, "%d,%s\n", &id, &dna);
					if (strStr(dna, subDNA))
					{
						dnaMatch[numOfDna].id = id;
						strCpy(dnaMatch[numOfDna].dna, dna);
						numOfDna++;
					}
				}
			}
			rewind(fp);

		}

		return found;
	}
	// Sorts the dynamic array of DNA matches found in the file based on the ids in ascending order.
	void sort()
	{
		int i, j;
		for (i = 0; i < numOfDna - 1; i++) 
		{
			for (j = 0; j < numOfDna - i - 1; j++) 
			{
				if (dnaMatch[j].id > dnaMatch[j + 1].id) 
				{
					int a;
					a = dnaMatch[j].id;
					dnaMatch[j].id = dnaMatch[j + 1].id;
					dnaMatch[j + 1].id = a;
				}
			}
		}
	}
	// Displays the dynamic DNA records
	void displayMatches()
	{
		int i;
		for (i = 0; i < numOfDna; i++) 
			cout << i + 1 << ") " << dnaMatch[i].id << ": " << endl << dnaMatch[i].dna << endl <<
				"======================================================================" << endl;

	}
	// Deallocates all the dynamic memory within the DNA array elements and the DNA array itself.
	void deallocate()
	{
		delete[] dnaMatch;
		dnaMatch = nullptr;
	}
	// Finalizes the program by releasing the resources allocated by the program
	void endSearch()
	{
		fflush(fp);
		fclose(fp);
		fp = NULL;
		delete[] dnaMatch;
		dnaMatch = nullptr;
		cout << "DNA Search Program Closed." << endl;
	}
	void initialize(int allocSize)
	{
		numOfDna = 0;
		dnaArrSize = allSize = allocSize;
		dnaMatch = new DNAStrand[allSize];
	}

}