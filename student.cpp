#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>

//Constructors
Student::Student() {
	this->studentID = " ";
	this->firstName = " ";
	this->email = " ";
	this->age = " ";
	for (int i = 0; i < daysInCourseArraySize; i++) {
		this->daysInCourse[i] = 0;
	}
	this->degreeType = DegreeType::NETWORK;
}

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string email, double daysInCourse[], DegreeType degreeType)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	for (int i = 0; i < daysInCourseArraySize; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeType = degreeType;
}

//Accessors
std::string Student::getStudentID()
{
	return this->Student::studentID;
}
std::string Student::getFirstName()
{
	return this->Student::firstName;
}
std::string Student::getLastName() 
{
	return this->Student::lastName;
}
std::string Student::getEmail()
{
	return this->Student::email;
}
double* Student::getDaysInCourse()
{
	return this->Student::daysInCourse;
}
DegreeType Student::getDegreeType()
{
	return this->Student::degreeType;
}

/* FOR COMPARISON
double* Book::getPrices() {
	return this->prices;
}
*/

//Mutators
void Student::setStudentID(std::string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(std::string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(std::string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(std::string email) {
	this->email = email;
}
void Student::setDaysInCourse(double daysInCourse[]) {
	for (int i = 0; i < daysInCourseArraySize; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	};
}
void Student::setDegreeProgram(DegreeType degreeType) {
	this->degreeType = degreeType;
}

void Student::print() {
	std::cout << std::left << std::setw(10) << this->studentID;
	std::cout << std::left << std::setw(10) << this->firstName;
	std::cout << std::left << std::setw(10) << this->lastName;
	std::cout << std::left << std::setw(35) << this->email;
	for (int i = 0; i < daysInCourseArraySize; i++) {
		std::cout << std::left << std::setw(10) << this->daysInCourse[i];
	}
	std::cout << std::left << std::setw(10) << degreeTypeStrings[static_cast<int>(degreeType)];
	std::cout << std::endl;
}