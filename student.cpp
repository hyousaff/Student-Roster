/*
Name: Hamza Yousaf
Project: Class Roster
file: student.cpp
date created: 11/2/2023
*/


// setting up student.cpp
#pragma once
#include "student.h"
#include "degree.h"
// #include <iostream>
// #include <string>


// Creating a parameterless constructor in case it is called.
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysSize; i++) this->daysinCourse[i] = 0;
	this->degreeProgram = DegreeProgram::UNASSIGNED;
}

// Creating a parameter constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysinCourse[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysSize; i++) this->daysinCourse[i] = daysinCourse[i];
	this->degreeProgram = degreeProgram;
}

// Destructor - doesnt do anything becuase array size is already set
Student::~Student() {}

// setting up getters
string Student::getSID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysinCourse() { return this->daysinCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

// setting up setters
void Student::setSID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }

void Student::setDaysinCourse(int daysinCourse[]) 
{ 
	this->daysinCourse[0] = daysinCourse[0];
	this->daysinCourse[1] = daysinCourse[1];
	this->daysinCourse[2] = daysinCourse[2];
}

void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

// printing header for nicer looks
void Student::printHeader()
{
	cout << " ID | First Name | Last Name | Email | Age | Days in Course | Degree Program\n";
}

// Printing rest of student information
void Student::print() 
{
	cout << this->getSID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysinCourse()[0]<< ",";
	cout << this->getDaysinCourse()[1] << ",";
	cout << this->getDaysinCourse()[2] << '\t';
	cout << DegreeTypeStrings[this->getDegreeProgram()] << '\n';
}