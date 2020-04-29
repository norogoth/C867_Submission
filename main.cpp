// C867_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "student.h"
#include "roster.h"

int main()
{
    std::cout << "Test output\n";

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
}