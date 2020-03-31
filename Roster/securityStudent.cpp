// Degree header for WGU - C867 - PA (5/11) - Ver. 0.4a - Last Edit 2020.03.24
/*
Man-Lung, Chau (Ricky)
001314629
C++
*/
#include <iostream>
#include "securityStudent.h"
using namespace std;

//Empty Constructor
securityStudent::securityStudent()
{
	setDegreeType(SECURITY);
}

//Full Constructor
securityStudent::securityStudent(string sID, string fName, string lName, string eAddress, int sAge, int* daysToComplete, Degree degree)
{
	setDegreeType(SECURITY);
}

//Destructor
securityStudent::~securityStudent()
{
	Student::~Student();
}

//Getters
Degree securityStudent::getDegreeProgram()
{
	return SECURITY;
}

//Setters
void securityStudent::setDegreeType(Degree degreeType)
{
	this->degree = SECURITY;
}


//Print
void securityStudent::printDegree()
{
	this->Student::printDegree();
	cout << "SECURITY" << endl;
}


