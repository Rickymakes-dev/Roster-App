// Degree header for WGU - C867 - PA (10/11) - Ver. 0.5a - Last Edit 2020.03.31
/*
Man-Lung, Chau (Ricky)
001314629
C++
*/
#pragma once

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

const int rosterSize = 5;

class Roster 
{
public:
	//Setup
	int counter;
	int studentSeats;
	Student** classRosterArray;

	//Constructors
	Roster();
	Roster(int studentSeats);

	//Destructor
	~Roster();

	//main functions
	void add						(string row);
	void printAll					();
	void printInvalidEmails			();
	void printAverageDaysInCourse	(string sID);
	void printByDegreeProgram		(Degree degreeType);
	void remove						(string sID);
};