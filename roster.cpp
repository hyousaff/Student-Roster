/*
Name: Hamza Yousaf
Project: Class Roster
file: roster.cpp
date created: 11/2/2023
*/



// setting up the cpp side of roster

#include <iostream>
//#include <string>
//#include <array>
#include "roster.h"

using namespace std;

// PARSING FUNCTION
void Roster::parse(string studentdata)
{

	// looking to find the -> , for location
	int rs = studentdata.find(",");
	string stuID = studentdata.substr(0, rs);

	//looking to find the first name 
	int ls = rs + 1;
	rs = studentdata.find(",", ls);
	string firstn = studentdata.substr(ls, rs-ls);

	//looking to find the last name 
	ls = rs + 1;
	rs = studentdata.find(",", ls);
	string lastn = studentdata.substr(ls, rs-ls);

	//looking to find email address
	ls = rs + 1;
	rs = studentdata.find(",", ls);
	string emaila = studentdata.substr(ls, rs-ls);

	//looking to find student age
	// also need to convert string to interger to find properly
	ls = rs + 1;
	rs = studentdata.find(",", ls);
	int age = stoi(studentdata.substr(ls, rs-ls));

	//looking to find Average days in first course
	ls = rs + 1;
	rs = studentdata.find(",", ls);
	int avg1 = stoi(studentdata.substr(ls, rs - ls));

	//looking to find Average days in second course
	ls = rs + 1;
	rs = studentdata.find(",", ls);
	int avg2 = stoi(studentdata.substr(ls, rs - ls));

	//looking to find Average days in third course
	ls = rs + 1;
	rs = studentdata.find(",", ls);
	int avg3 = stoi(studentdata.substr(ls, rs - ls));

	//looking for degree program
	// default will be security
	ls = rs + 1;
	rs = studentdata.find(",", ls);
	string degree = studentdata.substr(ls, rs - ls);

	DegreeProgram dp = SECURITY;
	if (degree == "NETWORK") {
		dp = NETWORK;
	}
	if (degree == "SOFTWARE") {
		dp = SOFTWARE;
	}

	add(stuID, firstn, lastn, emaila, age, avg1, avg2, avg3, dp);

}

//VOID ADD FUNCTION
void Roster::add(string stuID, string stuFName, string stuLName,
	string stuEmail, int StuAge, int studaysInCourse1, int
	studaysInCourse2, int studaysInCourse3, DegreeProgram studp)
{
	int CourseDayArray[3] = { studaysInCourse1, studaysInCourse2, studaysInCourse3 };
	classRosterArray[++lastIndex] = new Student(stuID, stuFName, stuLName,
		stuEmail, StuAge, CourseDayArray, studp);
}

//USING PRINT ALL
void Roster::printAll()
{
	Student::printHeader();
		for (int i = 0; i <= Roster::lastIndex; i++) 
			Roster::classRosterArray[i]->print();


}


// PRINT BY DEGREE PROGRAM
void Roster::printByDegreeProgram(DegreeProgram studp)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == studp)
			classRosterArray[i]->print();
	}
	cout << endl;
}

// PRINT AVERAGE DAYS IN COURSE
void Roster::printAverageDaysInCourse(string stuID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
		if (classRosterArray[i]->getSID() == stuID) {
			cout << classRosterArray[i]->getSID() << " = ";
			cout << (classRosterArray[i]->getDaysinCourse()[0]
				+ classRosterArray[i]->getDaysinCourse()[1]
				+ classRosterArray[i]->getDaysinCourse()[2]) / 3.0
				<< endl;
		}
	cout << endl;
}

//CHECKING FOR INVALID EMAILS, IF YES, PRINT THEN
void Roster::printInvalidEmails()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string stuEmail = (classRosterArray[i]->getEmailAddress());
		if ((stuEmail.find("@") != string::npos) && // checking for @
			(stuEmail.find(".") != string::npos)) // checking for .
		{
			if (stuEmail.find(" ") != string::npos) // checking for space
			{
				cout << stuEmail << endl;
			}	
		}
		else 
		{
			cout << stuEmail << endl;
		}
	}
}

// REMOVAL PROCESS
void Roster::remove(string stuID)
{
	bool success = false; // assuming the data we are looking for is not there
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getSID() == stuID)
		{
			success = true; // data is found
			if (i < RosterSize - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[RosterSize - 1];
				classRosterArray[RosterSize - 1] = temp;
			}
			Roster::lastIndex--; //Deleted record is not visible anymore
		}
	}
	if (success)
	{
		cout << stuID << " has been deleted successfully" << endl;
	}
	else cout << stuID << "student is not found (remove success)" << endl;
}

//DESTRUCTOR SET UP
Roster::~Roster()
{
	cout << "Removal Tool (Destructor) " << endl << endl;
	for (int i = 0; i < RosterSize; i++)
	{
		cout << "Removing data of Students : " << i + 1 << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}

}



