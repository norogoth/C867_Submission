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


}

void Roster::remove(std::string studentID) {

}

void Roster::printAll() {
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

		Roster::classRosterArray[i] = new Student(studentID, firstName, lastName, email, daysInCourse, degreeType);
	}
}