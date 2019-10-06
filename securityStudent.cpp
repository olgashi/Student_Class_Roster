//
// Created by Olga Shiryaeva on 10/5/19.
//
#include <iostream>
#include "securityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent():Student()
{
    degreeType = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToCompleteCourse[], DegreeType degreeType):Student(studentID, firstName, lastName, studentEmail, studentAge, daysToCompleteCourse)
{
    degreeType = SECURITY;
}

DegreeType SecurityStudent::getDegreeProgram()
{
    return SECURITY;
}

void SecurityStudent::print()
{
    this->Student::print();
    cout << "SECURITY" <<"\n";
}

SecurityStudent::~SecurityStudent()
{
    Student::~Student();
}