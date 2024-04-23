/*
Name: Hamza Yousaf
Project: Class Roster
file: student.h
date created: 11/2/2023
*/



// setting up student header file
#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "degree.h"

using std::cout;
using std::string;
using namespace std;

// making student class
class Student {
	// public section only for day array size
public:
	const static int daysSize = 3;

	// private section
private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysinCourse[daysSize]; // array size will match the set array size
	DegreeProgram degreeProgram;

public:
	Student(); // constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysinCourse[], DegreeProgram degreeProgram);
	~Student(); // destructor

	// Getters (accessors)
	
	string getSID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysinCourse();
	DegreeProgram getDegreeProgram();

	// setters (mutators)
	
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setSID(string ID);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysinCourse(int daysinCourse[]);
	void setDegreeProgram(DegreeProgram dp);

	static void printHeader();

	// displaying data
	void print();
};
