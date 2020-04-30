#pragma once
#include "student.h"
class Roster
{
protected:
	int classSize = 5;
	int lastIndex = -1;
	Student** classRosterArray = new Student* [classSize]; //creating array of pointers to Students

public:
	//Constructors
	Roster(int classSize);
	
	//Accessors
	
	
	//Mutators
	
	
	//Methods
	void parseAndAddToRoster(std::string dataRow, int i);
	void add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(std::string studentID);
	void printAll();
	void  printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printbyDegreeProgram(DegreeProgram degreeProgram);

	//destructor
	~Roster();




















};

