#include "roster.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "degree.h"

//Constructors
Roster::Roster(int classSize) {
	this->classSize = classSize;
}

//Accessors


//Mutators


//Methods

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degreeType) {

	classSize++;
	Student** tempClassRosterArray = new Student * [classSize];
	double daysInCourse[3];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
	Student* newStudent = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeType);
	for (int i = 0; i < classSize - 1; i++) {
		tempClassRosterArray[i] = Roster::classRosterArray[i];
	}
	tempClassRosterArray[classSize - 1] = newStudent;
	Roster::classRosterArray = tempClassRosterArray;
}

void Roster::remove(std::string studentID) {
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			Student** newClassRosterArray = new Student * [classSize-1];
			for (i; i < classSize-1; i++) {
				newClassRosterArray[i] = classRosterArray[i + 1];
			}
			classSize--;
			this->classRosterArray = new Student * [classSize];
			for (int i = 0; i < classSize; i++) {
				this->classRosterArray[i] = newClassRosterArray[i];
			}
			i = classSize + 1;
		}
	}
}

void Roster::printAll() {
	std::cout << std::left << std::setw(10) << "studentID";
	std::cout << std::left << std::setw(10) << "First";
	std::cout << std::left << std::setw(10) << "Last";
	std::cout << std::left << std::setw(35) << "email";
	std::cout << std::left << std::setw(30) << "Days in Course";
	std::cout << std::left << std::setw(10) << "Degree Type";
	std::cout << std::endl;
	for (int i = 0; i < this->classSize; i++) {
		this->classRosterArray[i]->print();
	}
}

void Roster::parseAndAddToRoster(std::string dataRow, int i) {
	//parse
	if (this->lastIndex < this->classSize) {
		++this->lastIndex;
		int rightBound;
		int leftBound;

		rightBound = dataRow.find(",");
		std::string studentID = dataRow.substr(0,rightBound);

		leftBound = rightBound + 1;
		rightBound = dataRow.find(",",leftBound);
		std::string firstName = dataRow.substr(leftBound, rightBound - leftBound);

		leftBound = rightBound + 1;
		rightBound = dataRow.find(",", leftBound);
		std::string lastName = dataRow.substr(leftBound, rightBound - leftBound);

		leftBound = rightBound + 1;
		rightBound = dataRow.find(",", leftBound);
		std::string email = dataRow.substr(leftBound, rightBound - leftBound);

		leftBound = rightBound + 1;
		rightBound = dataRow.find(",", leftBound);
		int age = std::stoi(dataRow.substr(leftBound, rightBound - leftBound));

		leftBound = rightBound + 1;
		rightBound = dataRow.find(",", leftBound);
		int daysInCourseOne = std::stoi(dataRow.substr(leftBound, rightBound - leftBound));

		leftBound = rightBound + 1;
		rightBound = dataRow.find(",", leftBound);
		int daysInCourseTwo = std::stoi(dataRow.substr(leftBound, rightBound - leftBound));

		leftBound = rightBound + 1;
		rightBound = dataRow.find(",", leftBound);
		int daysInCourseThree = std::stoi(dataRow.substr(leftBound, rightBound - leftBound));

		double daysInCourse[] = {daysInCourseOne*1.0, daysInCourseTwo * 1.0, daysInCourseThree * 1.0 };

		leftBound = rightBound + 1;
		rightBound = dataRow.find(",", leftBound);
		std::string degreeTypeAsString = dataRow.substr(leftBound, rightBound - leftBound);
		DegreeType degreeType = lookup[degreeTypeAsString];

		Roster::classRosterArray[i] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeType);
	}
}