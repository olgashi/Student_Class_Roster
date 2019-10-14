//
// Created by Olga Shiryaeva on 10/5/19.
//
#pragma once
#include <string>
#include <iostream>
#include "student.h"

// Roster stores student records
class Roster {
private:
    int lastIndex;// Index of last student record in roster
    int capacity;// The maximum size of the roster
    Student** classRosterArray;
public:
    Roster();// Empty constructor creates roster & initializes all fields to default values
    Roster(int capacity);// Second constructor performs the same actions as above, but sets maximum size

    Student* getStudentAt(int index);
    void parseThenAdd(string datarow);// Parses given strings with student records, creates student objects, and adds them to the roster
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degree);
    void printAll();// Prints all students in roster
    bool remove(string studentID);// Removes a student based on its ID
    void printAverageDaysInCourse(string studentID);// Prints students average days in course
    void printInvalidEmails();// Determines invalid emails and prints
    void printByDegreeProgram(int degreeProgram) ;// Prints students with given degree type
    ~Roster();//Destructor destroys the roster, releasing any resources it requested dynamically
};