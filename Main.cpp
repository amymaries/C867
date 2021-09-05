#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "degree.h"
#include "student.h"
#include "Roster.h"
using namespace std;


int main() {
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Amy ,Saunders,asaund9@wgu.edu,45,33,23,13,SOFTWARE"
	};

	int numStudents = 5;

	Roster* classRoster = new Roster(numStudents);


	cout << "C867 Scripting and Programming Applications, written in C++ by Amy Saunders, Student ID: 686585 " << endl;

	cout << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->parseThenAdd(studentData[i]);
	}

	cout << "Student Roster:" << endl;
	classRoster->printAll();


	cout << endl;

	cout << "Invalid student emails:" << endl;
	classRoster->printInvalidEmails();

	cout << endl;

	cout << "Average days in course per student:" << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i)->getStudentId());
	}

	cout << endl;

	cout << "Students in the software degree program: " << endl;
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);

	cout << endl;

	classRoster->remove("A3");

	cout << endl;

	classRoster->printAll();

	cout << endl;

	classRoster->remove("A3");

	system("pause");

	return 0;
}