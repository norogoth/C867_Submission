// C867_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"

int main()
{
    //Print Out Required Things
    std::string bar = "===================================";
    std::cout << "C867 Scripting and Programming Applications" << std::endl;
    std::cout << bar << std::endl;
    std::cout << "Language: C++" << std::endl;
    std::cout << "ID: 001236202" << std::endl;
    std::cout << "Name: Landon Aaker" << std::endl;
    std::cout << bar << std::endl;


    const std::string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Landon,Aaker,laaker1@wgu.edu,28, 20, 30, 32, 40,SOFTWARE",
    };
    Roster roster = Roster(5);
    for (int i = 0; i < 5; i++) {
        roster.parseAndAddToRoster(studentData[i],i);
    }
    roster.printAll();
    roster.remove("A3");
    roster.printAll();
    roster.remove("A3");
    //roster.~Roster(); destructor called automatically
}