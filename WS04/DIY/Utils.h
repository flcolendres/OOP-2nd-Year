#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#include "Robot.h"
namespace sdds {
	void resetVal(char* name, char* location, double* weight, double* width, double* height, double* speed, bool* deployed);
	void dealloc(char* name, char* location);
}

#endif