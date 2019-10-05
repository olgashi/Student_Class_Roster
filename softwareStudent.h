//
// Created by Olga Shiryaeva on 10/5/19.
//
#pragma once
#include <string>
#include "degree.h"
#include "student.h"
class SoftwareStudent : public Student
{
public:
//    constructor
    SoftwareStudent();
    SoftwareStudent(
            string studentID;
    string firstName;
    string lastName;
    string studentEmail;
    int studentAge;
    int daysToCompleteCourse[];
    Degree degreeType;
    )

    Degree getDegreeProgram();
    void print();
//destructor
    ~SoftwareStudent();
};