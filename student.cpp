#include "student.h"

//Constructors
Student::Student() {
	this->studentID = " ";
	this->firstName = " ";
	this->email = " ";
	this->age = " ";
	this->daysInCourse = " ";
	this->degreeProgram = " ";
}

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string email, std::string daysInCourse, std::string degreeProgram)
{
	this->studentID = studentID;
}

//getters
std::string Student::getStudentID()
{
	return Student::studentID;
}
std::string Student::getFirstName()
{
	return Student::firstName;
}
