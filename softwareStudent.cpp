//
// Created by Olga Shiryaeva on 10/5/19.
//
#include <iostream>
#include "softwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent():Student()
{
    degreeType = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToCompleteCourse[], DegreeType degreeType):Student(studentID, firstName, lastName, studentEmail, studentAge, daysToCompleteCourse)
{
    degreeType = SOFTWARE;
}

DegreeType SoftwareStudent::getDegreeProgram()
{
    return SOFTWARE;
}

void SoftwareStudent::print()
{
    this->Student::print();
    cout << "SOFTWARE" <<"\n";
}

SoftwareStudent::~SoftwareStudent()
{
    Student::~Student();
}