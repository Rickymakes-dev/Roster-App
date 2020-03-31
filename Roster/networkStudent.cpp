// Degree header for WGU - C867 - PA (7/11) - Ver. 0.4a - Last Edit 2020.03.24
/*
Man-Lung, Chau (Ricky)
001314629
C++
*/
#include <iostream>
#include "networkStudent.h"
using namespace std;

//Empty Constructor
networkStudent::networkStudent()
{
	setDegreeType(NETWORK);
}

//Full Constructor
networkStudent::networkStudent(string sID, string fName, string lName, string eAddress, int sAge, int* daysToComplete, Degree degree)
{
	setDegreeType(NETWORK);
}

//Destructor
networkStudent::~networkStudent()
{
	Student::~Student();
}

//Getters
Degree networkStudent::getDegreeProgram()
{
	return NETWORK;
}

//Setters
void networkStudent::setDegreeType(Degree degreeType)
{
	this->degree = NETWORK;
}


//Print
void networkStudent::printDegree()
{
	this->Student::print();
	cout << "NETWORK" << endl;
}


