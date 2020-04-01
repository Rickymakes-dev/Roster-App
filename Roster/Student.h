// Degree header for WGU - C867 - PA (2/11) - Ver. 0.5a - Last Edit 2020.03.31
/*
Man-Lung, Chau (Ricky)
001314629
C++
*/
#pragma once
#include <iostream>
#include <string>
//#include <vector>
#include "degree.h"

using namespace std;

class Student
{
public:
	const static int daysToCompleteSize = 3;

protected:
	//Student Class setup
	string	studentID;
	string	firstName;
	string	lastName;
	string	emailAddress;
	int		studentAge;
	//vector<int> daysToComplete;	//(Maybe use Dynamic Vector)
	int*	daysToComplete; 		//Pointers for array
	Degree	degree;					//Can be removed from contructor if needed

public:
	//Constructors
	Student();						//Empty Constructor
	Student(string sID, string fName, string lName, string eAddress, int sAge, int daysToComplete[], Degree degree);

	//Deconstructor
	~Student();

	//Getters & Setters
	//Getters
	string			getStudentID();
	string			getFirstName();
	string			getLastName();
	string			getEmailAddress();
	int				getStudentAge();
	int*			getDaysToComplete();
	virtual Degree	getDegreeProgram() = 0;

	//Setters
	void			setStudentID			(string sID);
	void			setFirstName			(string fName);
	void			setLastName				(string lName);
	void			setEmailAddress			(string eAddress);
	void			setStudentAge			(int sAge);
	void			setDaysToComplete		(int daysToComplete[]);
	//virtual void	setDegreeType			(Degree degreeType) = 0;

	//Print
	virtual void	print();
	virtual void	printEmailAddress();

	
};

