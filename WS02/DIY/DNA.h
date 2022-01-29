/**
* Francis Lloyd Colendres
* flcolendres@myseneca.ca
* 145498200
* Jan. 28, 2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_DNA_H
#define SDDS_DNA_H
namespace sdds {

	struct DNAStrand
	{
		int id;
		char dna[1000 + 1];
	};

	bool beginSearch(const char* filename);
	bool read(const char* subDNA);
	void sort();
	void displayMatches();
	void deallocate();
	void endSearch();
	void initialize(int allocSize);
}

#endif