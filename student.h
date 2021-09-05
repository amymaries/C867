#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student {
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numDays[3]; //Number of days per 3 courses
	DegreeProgram degreeProgram;

public:
	// Constructors  
	Student(); // empty constructor
	Student(string studentId, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram dp);
	const static int numDaysArraySize = 3;

	// getters for each instance field 
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getnumDays();
	DegreeProgram getdegreeProgram();

	// setters, each passing in a value and returning void 
	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setnumDays(int numDays[]);
	void setDegree(DegreeProgram degreeProgram);
	void print();

	~Student();
};
