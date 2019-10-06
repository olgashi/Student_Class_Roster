//
// Created by Olga Shiryaeva on 10/5/19.
//
#pragma once
#include <string>
#include "degree.h"
#include "student.h"
class SecurityStudent : public Student
{
public:
//    constructor
    SecurityStudent();
    SecurityStudent(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToCompleteCourse[], DegreeType degreeType);

    DegreeType getDegreeProgram();
    void print();
//destructor
    ~SecurityStudent();
};