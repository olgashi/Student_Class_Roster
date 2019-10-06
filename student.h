//
// Created by Olga Shiryaeva on 10/5/19.
//
#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student //class represents a Student
{
public:
    const static int daysToCompleteSize = 3;

protected:
    string studentID;
    string firstName;
    string lastName;
    string studentEmail;
    int studentAge;
    int daysToCompleteCourse[daysToCompleteSize];
    DegreeType degreeType;

public:
    Student();//empty constructor
    Student(string studentId, string firstName, string lastName, string studentEmail, int studentAge, int daysToCompleteCourse[]);//full constructor

//    getters
    string getStudentID();
    string getStudentFirstName();
    string getStudentLastName();
    string getStudentEmail();
    int getStudentAge();
    int* getDaysToCompleteCourse();
    virtual DegreeType getDegreeProgram() = 0;

//    setters
    void setStudentID(string studentID);
    void setStudentFirstName(string firstName);
    void setStudentLastName(string lastName);
    void setStudentEmail(string studentEmail);
    void setStudentAge(int studentAge);
    void setDaysToCompleteCourse(int daysToCompleteCourse[]);
    virtual void print() = 0;

//    destructor
    virtual ~Student();
};