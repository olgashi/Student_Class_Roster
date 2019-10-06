//
// Created by Olga Shiryaeva on 10/5/19.
//
#include <iostream>
#include "networkStudent.h"
using std::cout;

NetworkStudent::NetworkStudent():Student()
{
    degreeType = NETWORKING;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToCompleteCourse[], DegreeType degreeType):Student(studentID, firstName, lastName, studentEmail, studentAge, daysToCompleteCourse)
{
    degreeType = NETWORKING;
}

DegreeType NetworkStudent::getDegreeProgram()
{
    return NETWORKING;
}

void  NetworkStudent::print()
{
    this->Student::print();
    cout << "NETWORK" <<"\n";
}

NetworkStudent::~NetworkStudent()
{
    Student::~Student();
}