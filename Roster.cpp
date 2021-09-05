#include <string>
#include <iostream>
#include "student.h"
#include "Roster.h"
#include "degree.h"
using namespace std;

Roster::Roster() {  //Empty constructor sets to default
	this->rosterSize = 0;
	this->index = -1; //Means empty because 0 is a valid index in an array
	this->classRosterArray = nullptr;
}

Roster::Roster(int rosterSize) { //Max capacity for the roster
	this->rosterSize = rosterSize;
	this->index = -1; //means empty
	this->classRosterArray = new Student * [rosterSize]; //index pointers pinting at array of students
}

//calls a separate add() method
void Roster::parseThenAdd(string row) { //refer to long strings as a row
	if (index < rosterSize) {
		index++; // increment (start at -1)
	}
	//parse through each student string, extracting substrings between commas
	//Get ID, assign it to a temp variable
	int rhs = row.find(","); // parse strings to find commas, rhs is right hand side
	string sID = row.substr(0, rhs);

	//Get student first name
	int lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string sFirstName = row.substr(lhs, rhs - lhs);

	//Get student last name
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string sLastName = row.substr(lhs, rhs - lhs);

	//Get student email
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string sEmail = row.substr(lhs, rhs - lhs);

	//Get student age
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string sAge = row.substr(lhs, rhs - lhs);
	int age = stoi(sAge); //string to integer function stoi

	//Get NumDays1  -- array of days in courses
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int nD1 = stoi(row.substr(lhs, rhs - lhs));

	//Get NumDays2
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int nD2 = stoi(row.substr(lhs, rhs - lhs));

	//Get NumDays3
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int nD3 = stoi(row.substr(lhs, rhs - lhs));

	//Get degree program
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	DegreeProgram degreeProgram;
	string degreeProgramStr = row.substr(lhs, rhs - lhs);
	if (degreeProgramStr == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (degreeProgramStr == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (degreeProgramStr == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}
	else { //barf and leave, lol!
		cerr << "Invalid book type! Exiting now!" << endl;
		exit(-1);
	}

	add(sID, sFirstName, sLastName, sEmail, age, nD1, nD2, nD3, degreeProgram);

}

//This method creates the student in the proper degree program and adds them to class, all parsed values passed in
void Roster::add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int nD1, int nD2, int nD3, DegreeProgram degreeProgram) {
	int numDays[Student::numDaysArraySize];

	numDays[0] = nD1;    //create array, be sure variables are public 
	numDays[1] = nD2;
	numDays[2] = nD3;

	classRosterArray[index] = new Student(sID, sFirstName, sLastName, sEmail, sAge, numDays, degreeProgram);
}

// Iterate through array of pointers to the students and call print method for each
void Roster::printAll() { 
	for (int i = 0; i <= this -> index; i++) {
		(this ->classRosterArray)[i]->print();
	}
}

//Remove student based on student ID number
void Roster::remove(string studentID){
	cout << "Removing student: " << studentID << "\n";
	bool success = false;
	for (int i = 0; i <= Roster::index; i++){
		if (classRosterArray[i]->getStudentId() == studentID){
			success = true;
			////if (i < index){
			//	Student* temp = classRosterArray[i];
			delete classRosterArray[i];
				classRosterArray[i] = classRosterArray[index];
				/*classRosterArray[index] = temp;
			}*/
			Roster::index--; //Note student not deleted, but cannot be acessed further.
		}
	}
	if (success){
		//cout << studentID << " removed from class roster" << endl << endl;
		//this->printAll();
	}
	else cout << studentID << " not found." << endl << endl;
}

//print average days in course
void Roster::printAverageDaysInCourse(string studentID) {

	int average = 0;

	for (int i = 0; i <= index; ++i) {
		string tempID = classRosterArray[i]->getStudentId();
		if (tempID == studentID) {
			average = ((classRosterArray[i]->getnumDays()[0] + classRosterArray[i]->getnumDays()[1] + classRosterArray[i]->getnumDays()[2]) / 3.0);
			cout << "Student ID " << studentID << " average is: " << average << endl;
		}
	}
}

//locate invalid email addresses
void Roster::printInvalidEmails() {
	for (int i = 0; i < Roster::index; ++i) {
		string sEmail = classRosterArray[i]->getEmail();
		if ((sEmail.find("@") == string::npos || sEmail.find(".") == string::npos) || (sEmail.find(" ") != string::npos)) {
			cout << sEmail << endl;
		}
	}
}

//print by degree program
void Roster::printByDegreeProgram(DegreeProgram degree) {
	for (int i = 0; i <= Roster::index; ++i) {
		DegreeProgram tempDegree = classRosterArray[i]->getdegreeProgram();
		if (tempDegree == degree) {
			classRosterArray[i]->print();
		}
	}
}

Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
}

Roster::~Roster() {
	for (int i = 0; i <= index; ++i) {
		delete classRosterArray[i];
	}
	delete classRosterArray;
}

