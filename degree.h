/*
Name: Hamza Yousaf
Project: Class Roster
file: degree.h
date created: 11/2/2023
*/



// setting up all the degree types

#pragma once
#include <string>

using namespace std;


enum DegreeProgram 
{
	UNASSIGNED,
	SECURITY, 
	NETWORK, 
	SOFTWARE,
	
};

// putting degree types in a string value for other file easy use
static const std::string DegreeTypeStrings[] = {"UNASSIGNED", "SECURITY","NETWORK","SOFTWARE"};

