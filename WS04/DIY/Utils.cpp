#include "Utils.h"

namespace sdds
{

	void resetVal(char* name, char* location, double* weight, double* width, double* height, double* speed, bool* deployed)
	{
		name = location = nullptr;
		*weight = *width = *height = *speed = 0;
		*deployed = 0;
	}
	void dealloc(char* name, char* location)
	{
		delete[] name;
		delete[] location;
	}

}

