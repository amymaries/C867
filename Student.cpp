#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

// Constructors 
Student::Student(){ //Empty constructor will set all values to default
	this->studentID = ""; //assign empty strings and 0 for ints
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < numDaysArraySize; ++i) {this->numDays[i] = 0;}
	this->degreeProgram = degreeProgram; //set all to zero
}
//The full constructor
Student::Student(string studentId, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram degreeProgram) {
	this->studentID = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < numDaysArraySize; ++i) {this->numDays[i] = numDays[i];} this->degreeProgram = degreeProgram;
}

// getters 
string Student::getStudentId() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmail() {
	return email;
}
int Student::getAge() {
	return age;
}
int* Student::getnumDays() {
	return numDays;
}
DegreeProgram Student::getdegreeProgram() {
	return degreeProgram;
}


// setters - each returns void and acepts a parameter
void Student::setStudentId(string studentId) {
	this->studentID = studentId;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setnumDays(int numDays[]) {
	for (int i = 0; i < numDaysArraySize; ++i) { this->numDays[i] = numDays[i]; }
}

void Student::setDegree(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


// Print Method displays all fields
void Student::print() {
	cout << studentID;
	cout << "\tFirst name: " << firstName;
	cout << "\tLast name: " << lastName;
	cout << "\tAge: " << age;

	int* days = numDays;
	cout << "\tDays in courses: {" << days[0] << ", " << days[1] << ", " << days[2] << "} ";
	cout << "Degree Program: " << degreeProgramStr[getdegreeProgram()] << endl;
}

// Destructors 
Student::~Student() {

}
