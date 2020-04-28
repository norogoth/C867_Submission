#pragma once
#include <string>

class Student
{
protected:
	std::string studentID, firstName, lastName, email, age, daysInCourse, degreeProgram;

//Constructors
Student();
Student(std::string studentID, std::string firstName, std::string lastName, std::string email, std::string daysInCourse, std::string degreeProgram);

//accessors
std::string getStudentID();
std::string getFirstName();
std::string getLastName();
std::string getEmail();
std::string getDaysInCourse();
std::string getDegreeProgram();

//Mutators
void setStudentID(std::string studentID);
void setFirstName(std::string firstName);
void setLastName(std::string lastName);
void setEmail(std::string email);
void setDaysInCourse(std::string daysInCourse);

};