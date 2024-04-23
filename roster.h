/*
Name: Hamza Yousaf
Project: Class Roster
file: roster.h
date created: 11/2/2023
*/


// setting up roster header file

#pragma once
#include "degree.h"
#include "student.h"
//#include <iostream>
#include <iomanip>
//#include <string>

using namespace std;

// setting up roster class
class Roster 
{

//private section
private:
	
	const static int RosterSize = 5; // roster size declared
	

// public section
public:
	
	int lastIndex = -1;
	Student* classRosterArray[RosterSize];

	void parse(string stuData);

	void add(string stuID, string stuFName, string stuLName, string stuEmail, int StuAge, int studaysInCourse1, int studaysInCourse2, int studaysInCourse3, DegreeProgram dp);

	void printAll();
	void printByDegreeProgram(DegreeProgram dp);
	void printInvalidEmails();
	void printAverageDaysInCourse(string stuID);

	void remove(string stuID);

	// destructor
	~Roster();
	
};