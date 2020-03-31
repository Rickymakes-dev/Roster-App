// Degree header for WGU - C867 - PA (9/11) - Ver. 0.4a - Last Edit 2020.03.24
/*
Man-Lung, Chau (Ricky)
001314629
C++
*/
#include <iostream>
#include "softwareStudent.h"
using namespace std;

//Empty Constructor
softwareStudent::softwareStudent()
{
	setDegreeType(SOFTWARE);
}

//Full Constructor
softwareStudent::softwareStudent(string sID, string fName, string lName, string eAddress, int sAge, int* daysToComplete, Degree degree)
{
	setDegreeType(SOFTWARE);
}

//Destructor
softwareStudent::~softwareStudent()
{
	Student::~Student();
}

//Getters
Degree softwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

//Setters
void softwareStudent::setDegreeType(Degree degreeType)
{
	this->degree = SOFTWARE;
}


//Print
void softwareStudent::printDegree()
{
	this->Student::print();
	cout << "SOFTWARE" << endl;
}