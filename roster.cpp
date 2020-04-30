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

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	classSize++;
	Student** tempClassRosterArray = new Student * [classSize];
	double daysInCourse[3];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
	Student* newStudent = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
	for (int i = 0; i < classSize - 1; i++) {
		tempClassRosterArray[i] = Roster::classRosterArray[i];
	}
	tempClassRosterArray[classSize - 1] = newStudent;
	Roster::classRosterArray = tempClassRosterArray;
}


void Roster::remove(std::string studentID) {
	Student** newClassRosterArray = new Student * [classSize];
	bool studentFound = false;
	for (int k = 0; k < classSize; k++) {
		if (classRosterArray[k]->getStudentID() == studentID) {
			studentFound = true;
			int indexOfDeletion = k;
			classSize--;
			for (int i = 0; i < indexOfDeletion;  i++) {
				newClassRosterArray[i] = classRosterArray[i];
			}
			for (int i = indexOfDeletion; i < classSize; i++) {
				newClassRosterArray[i] = classRosterArray[i + 1];
			}
			this->classRosterArray = new Student * [classSize];
			for (int i = 0; i < classSize; i++) {
				this->classRosterArray[i] = newClassRosterArray[i];
			}
		}
	}
	if (studentFound == false) {
		std::cout << "A student with that ID could not be found." << std::endl;
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
	std::cout << std::endl;
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
		DegreeProgram degreeType = lookup[degreeTypeAsString];

		Roster::classRosterArray[i] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeType);
	}
}

void  Roster::printAverageDaysInCourse(std::string studentID) {
	Student* student;
	bool studentFound = false;
	for (int i = 0; i < classSize; i++) {
		std::string currentStudentID = classRosterArray[i]->getStudentID();
		if (currentStudentID == studentID) {
			studentFound = true;
			student = classRosterArray[i];
			i = classSize;
			double sum = 0;
			for (int i = 0; i < 3; i++) {
				sum = sum + student->getDaysInCourse()[i];
			}
			double averageDays = round(sum*10 / 3)/10;
			std::cout << "Average days in each course for " << studentID << ": " << averageDays << "days." << std::endl;
		}
	}
	if (studentFound == false) {
		std::cout << "Student not found.";
	}
}
void Roster::printInvalidEmails() {
	for (int i = 0; i < classSize; i++) {
		std::string email = classRosterArray[i]->getEmail();
		if (email.find("@") == std::string::npos) {
			std::cout << email;
		}
		else if (email.find(".") == std::string::npos) {
			std::cout << email;
		}
		else if (email.find(" ") != std::string::npos) {
			std::cout << email;
		}
	}
}
void Roster::printbyDegreeProgram(DegreeProgram degreeProgram) {
	std::cout << std::left << std::setw(10) << "studentID";
	std::cout << std::left << std::setw(10) << "First";
	std::cout << std::left << std::setw(10) << "Last";
	std::cout << std::left << std::setw(35) << "email";
	std::cout << std::left << std::setw(30) << "Days in Course";
	std::cout << std::left << std::setw(10) << "Degree Type";
	std::cout << std::endl;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i]->getDegreeType() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {
	for (int i = 0; i < this->classSize; i++) {
		delete classRosterArray[i];
	}
	delete[] classRosterArray;
	//std::cout << "destructor running." << std::endl;
}