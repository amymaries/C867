#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

class Roster { // to hold data from student data table
public:
	int index; //index of last student on roster
	int rosterSize; //max size of roster
	Student** classRosterArray; // array of pointers
	Roster(); // empty constructor, initializes to default values
	Roster(int rosterSize); // constructor sets max size to let user determine size of array
	void parseThenAdd(string row); //parses the strings, creates student objects, adds them to roster
	void add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int nD1, int nD2, int nD3, DegreeProgram degreeProgram);
	void printAll(); //prints using print methods
	void remove(string sID);//removes students based on ID
	void printAverageDaysInCourse(string sID); //prints average days in course
	void printInvalidEmails(); //locates invalid email addresses
	void printByDegreeProgram(DegreeProgram degree); //prints students by degree program
	Student* getStudentAt(int index);

	~Roster(); // destroy roster
};
