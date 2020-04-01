// Degree header for WGU - C867 - PA (11/11) - Ver. 0.5a - Last Edit 2020.03.31
/*
Man-Lung, Chau (Ricky)
001314629
C++
*/

#include <iostream>
#include <string>
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "roster.h"
#include "degree.h"

using namespace std;


//Data setup
int charLen = 120;
Degree programSearch = SOFTWARE;

const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Man-Lung,Chau ,Mchau4@wgu.edu,24,5,12,24,SOFTWARE",
};

//Empty Constructors
Roster::Roster()
{
	this->counter = -1;
	this->studentSeats = 0;
	this->classRosterArray = nullptr;
}

//Full Constructors
Roster::Roster(int studentSeats)
{
	this->counter = -1;
	this->studentSeats = studentSeats;
	this->classRosterArray = new Student * [studentSeats];
}

//Destructor
Roster::~Roster()
{
	for (int i = 0; i < rosterSize; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}

#pragma region Index
/*
=====	Functions	=====
	-1:	ADD
	-2:	printAll
	-3:	printInvalidEmails
	-4:	printAverageDaysInCourse
	-5:	printByDegreeProgram
	-6:	remove
*/

#pragma endregion 

#pragma region -1:	ADD
//ADD
void Roster::add(string row)
{
	if (counter < studentSeats) {
		counter++;

		int numDaysArray[Student::daysToCompleteSize];


		if (row.substr(row.length() - 8, 8) == "SOFTWARE") {
			this->classRosterArray[counter] = new softwareStudent();
			//classRosterArray[counter]->setDegreeType(SOFTWARE);
		}

		else if (row.substr(row.length() - 7, 7) == "NETWORK") {
			this->classRosterArray[counter] = new networkStudent();
			//classRosterArray[counter]->setDegreeType(NETWORK);
		}

		else if (row.substr(row.length() - 8, 8) == "SECURITY") {
			this->classRosterArray[counter] = new securityStudent();
			//classRosterArray[counter]->setDegreeType(SECURITY);
		}
		else
		{
			cerr << "Degree Program Error!" << endl;
			system("pause");
		}

		//studentID
		int rhs = studentData[counter].find(",");
		classRosterArray[counter]->setStudentID(studentData[counter].substr(0, rhs));

		//firstName
		int lhs = rhs + 1;
		rhs = studentData[counter].find(",", lhs);
		classRosterArray[counter]->setFirstName(studentData[counter].substr(lhs, rhs - lhs));

		//lastName
		lhs = rhs + 1;
		rhs = studentData[counter].find(",", lhs);
		classRosterArray[counter]->setLastName(studentData[counter].substr(lhs, rhs - lhs));

		//emailAddress
		lhs = rhs + 1;
		rhs = studentData[counter].find(",", lhs);
		classRosterArray[counter]->setEmailAddress(studentData[counter].substr(lhs, rhs - lhs));

		//studentAge
		lhs = rhs + 1;
		rhs = studentData[counter].find(",", lhs);
		classRosterArray[counter]->setStudentAge(stoi(studentData[counter].substr(lhs, rhs - lhs)));

		//Days to complete[0]
		lhs = rhs + 1;
		rhs = studentData[counter].find(",", lhs);
		numDaysArray[0] = stoi(studentData[counter].substr(lhs, rhs - lhs));

		//Days to complete[1]
		lhs = rhs + 1;
		rhs = studentData[counter].find(",", lhs);
		numDaysArray[1] = stoi(studentData[counter].substr(lhs, rhs - lhs));

		//Days to complete[2]
		lhs = rhs + 1;
		rhs = studentData[counter].find(",", lhs);
		numDaysArray[2] = stoi(studentData[counter].substr(lhs, rhs - lhs));

		classRosterArray[counter]->setDaysToComplete(numDaysArray);
	}
	else
	{
		cerr << "Array overflow!" << endl;
		system("pause");
	}
}
#pragma endregion

#pragma region -2:	printAll
//printAll
void Roster::printAll()
{
	for (int i = 0; i < rosterSize; i++)
	{
		if (classRosterArray[i] != 0)
		{
			cout << i + 1 << "	";
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}
#pragma endregion

#pragma region -3:	printInvalidEmails
//printInvalidEmails
void Roster::printInvalidEmails()
{
	cout << "Invalid email address(es): " << endl;
	cout << endl;

	for (int i = 0; i < rosterSize; i++)
	{
		bool findAt = classRosterArray[i]->getEmailAddress().find('@') != std::string::npos;
		bool findPeriod = classRosterArray[i]->getEmailAddress().find('.') != std::string::npos;
		bool findSpace = classRosterArray[i]->getEmailAddress().find(' ') != std::string::npos;

		if (!findAt)
		{
			classRosterArray[i]->printEmailAddress();
			cout << "	**Shound include an at sign('@')" << endl;
			cout << endl;
		}
		else if (!findPeriod)
		{
			classRosterArray[i]->printEmailAddress();
			cout << "	**Shound include a period sign('.')" << endl;
			cout << endl;
		}
		else if (findSpace)
		{
			classRosterArray[i]->printEmailAddress();
			cout << "	**Should not include a space(' ')" << endl;
			cout << endl;
		}
	}
	cout << endl;
}
#pragma endregion

#pragma region -4:	printAverageDaysInCourse
//printAverageDaysInCourse
void Roster::printAverageDaysInCourse(string sID)
{
	bool found = false;

	for (int i = 0; i <= counter; i++) {
		if (this->classRosterArray[i]->getStudentID() == sID) 
		{
			found = true;
			int* days = classRosterArray[i]->getDaysToComplete();
			cout << "Average number of days per course for student " << sID << " is " << (days[0] + days[1] + days[2]) / 3 << " days" << endl;
		}
	}
}
#pragma endregion

#pragma region -5:	printByDegreeProgram
//printByDegreeProgram
void Roster::printByDegreeProgram(Degree degreeProgram) 
{
	for (int i = 0; i < rosterSize; i++)
	{
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
			cout << endl;
		}
	}
	cout << endl;
}
#pragma endregion

#pragma region -6:	remove
//remove
void Roster::remove(string sID)
{

	for (int i = 0; i <= counter; i++) 
	{
		if (classRosterArray[i] == nullptr) {
			cout << "ERROR: Student " << sID << " not found." << endl;
			break;
		}
		else if (sID == classRosterArray[i]->getStudentID()) {
			classRosterArray[i] = nullptr;
			cout << "Student " << sID << " removed." << endl;
		}
	}

}
#pragma endregion

#pragma region Misc
//Layout Misc
void dashLine()
{
	cout << string(charLen, '=') << endl;
}

void titleHeader(string callOut)
{
	cout << endl;
	dashLine();
	cout <<  " - " + callOut << endl;
	dashLine();
	cout << endl;
}

void idCallOut()
{
	dashLine();
	cout << "WGU - C867 - PA " << endl;
	cout << "Scripting And Programming Application" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: #001314629" << endl;
	cout << "Name: Ricky Chau" << endl;
	dashLine();
};
#pragma endregion

int main()
{
	//Info print out (Course title, Language used, SID, my name)
	idCallOut();

	//Create an instance of the Roster class called classRoster
	Roster* classRoster = new Roster(rosterSize);
	for (int i = 0; i < rosterSize; i++) {
		classRoster->add(studentData[i]);
	}

	//Console print start
	//Print All
	titleHeader("printAll()");
	classRoster->printAll();

	//Print Invalid Emails
	titleHeader("printInvalidEmails()");
	classRoster->printInvalidEmails();

	//Print Average Day In Course
	//loop through classRosterArray and for each element:
	titleHeader("printAverageDaysInCourse()");
	for (int i = 0; i < rosterSize; i++) 
	{
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentID());
	}
	cout << endl;

	//Print By Degree Program (Software)
	//Search term can be change in Data
	titleHeader("Print By Degree Program()");
	classRoster->printByDegreeProgram(programSearch);

	//Remove A3
	titleHeader("remove(A3)");
	classRoster->remove("A3");

	//Remove A3
	//Expected: The line below should print a message saying such a student with this ID was not found
	titleHeader("remove(A3) - expected student ID not found");
	classRoster->remove("A3");

	titleHeader("The End");
	system("pause");
	exit(-1);
}