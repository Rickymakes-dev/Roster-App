// Degree header for WGU - C867 - PA (4/11) - Ver. 0.5a - Last Edit 2020.03.31
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

class securityStudent : public Student
{
public:
	//Constructors
	securityStudent();
	securityStudent(string sID, string fName, string lName, string eAddress, int sAge, int* daysToComplete, Degree degree);

	//Destructor
	~securityStudent();

	//Getters
	Degree	getDegreeProgram();

	//Setters
	void	setDegreeType(Degree degreeType);

	//Print
	//void printDegree();

};
