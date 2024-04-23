/*
Name: Hamza Yousaf
Project: Class Roster
file: main.cpp
date created: 11/2/2023
*/




// Setting up the main cpp for the program to work completely

#include "roster.h"

using namespace std;

int main()
{
	


	// student Data Table with my information included to parse
	const string studentData[] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Hamza,Yousaf,hyousa2@wgu.edu,26,40,12,23,SOFTWARE"
	};

	cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS C867" << endl;
	cout << "PROJECT NAME: CLASS ROSTER" << endl;
	cout << "PROGRAMMING LANAUGE: C++" << endl;
	cout << "NAME: HAMZA YOUSAF" << endl;
	cout << "STUDENT ID: 011006052 " << endl;
	cout << endl; // making output cleaner

	
	const int RosterSize = 5;

	Roster classRoster;

	// student display
	for (int i = 0; i < RosterSize; i++) // displaying all of students in the roster
	classRoster.parse(studentData[i]);
	cout << "Roster of All Students: " << endl;
	classRoster.printAll();
	cout << endl;


	// Display according to Student Degree Type
	for (int i = 0; i < 4; i++)
	{
		cout << "Display of students sorted by degree type: " << DegreeTypeStrings[i] << endl;
		classRoster.printByDegreeProgram((DegreeProgram)i);
	}

	// Display of Student with Invalid Email Addresses
	cout << "Display of all students with invalid/unacceptable Email Adresses" << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	// Display of Student Average day in a course
	cout << "Display of a student Average day in course: " << endl;
	for (int i = 0; i < RosterSize; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getSID());
	
	}

	// Student Removal By ID
	cout << "Student ID A3 will be removed" << endl;
	classRoster.remove("A3");
	cout << endl;

	// PRINTING THE ROSTER AGAIN
	classRoster.printAll();
	cout << endl;

	cout << "Removing student A3.." << endl;
	classRoster.remove("A3 ");
	cout << endl;

	system("pause");
	return 0;

}