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

//Accessors
std::string Student::getStudentID()
{
	return Student::studentID;
}
std::string Student::getFirstName()
{
	return Student::firstName;
}
std::string Student::getLastName() 
{
	return Student::lastName;
}
std::string Student::getEmail()
{
	return Student::email;
}
std::string Student::getDaysInCourse()
{
	return Student::daysInCourse;
}
std::string Student::getDegreeProgram()
{
	return Student::degreeProgram;
}

//Mutators
void Student::setStudentID(std::string studentID) {
	this->studentID = studentID;
}
void setFirstName(std::string firstName) {

}
void setLastName(std::string lastName) {

}
void setEmail(std::string email) {

}
void setDaysInCourse(std::string daysInCourse) {

}

