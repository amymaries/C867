#pragma once
#include <string>
using namespace std;

enum DegreeProgram { 
	SECURITY, NETWORK, SOFTWARE 
}; // Three degree programs possible

//This array of strings is used for printing labels equivalent to enumerated values.
static const string degreeProgramStr[] = { "SECURITY", "NETWORK", "SOFTWARE" };

