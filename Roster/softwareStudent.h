// Degree header for WGU - C867 - PA (8/11) - Ver. 0.4a - Last Edit 2020.03.24
/*
Man-Lung, Chau (Ricky)
001314629
C++
*/
#pragma once

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

class softwareStudent : public Student
{
public:
	//Constructors
	softwareStudent();
	softwareStudent(string sID, string fName, string lName, string eAddress, int sAge, int* daysToComplete, Degree degree);

	//Destructor
	~softwareStudent();

	//Getters
	Degree	getDegreeProgram();

	//Setters
	void	setDegreeType(Degree degreeType);

	//Print
	void printDegree();

};
