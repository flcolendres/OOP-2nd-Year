#include "Utils.h"

namespace sdds
{

	void resetVal(double* weight, double* width, double* height, double* speed, bool* deployed)
	{
		*weight = *width = *height = *speed = 0;
		*deployed = 0;
	}
	void dealloc(char* name, char* location)
	{
	}

}

