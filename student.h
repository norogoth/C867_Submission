#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "degree.h"

class Student
{
protected:
	std::string studentID, firstName, lastName, email, degreeProgram;
	int age;
	static const int daysInCourseArraySize = 3;
	double daysInCourse[daysInCourseArraySize];
	DegreeType degreeType;

public:
//Constructors
Student();
Student(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, double daysInCourse[], DegreeType degreeProgram);

//accessors
std::string getStudentID();
std::string getFirstName();
std::string getLastName();
std::string getEmail();
int getAge();
double* getDaysInCourse();
DegreeType getDegreeType();

//Mutators
void setStudentID(std::string studentID);
void setFirstName(std::string firstName);
void setLastName(std::string lastName);
void setEmail(std::string email);
void setAge(int age);
void setDaysInCourse(double daysInCourse[]);
void setDegreeProgram(DegreeType degreeType);

//Methods
void print();
};

