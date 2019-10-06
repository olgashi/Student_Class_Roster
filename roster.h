//
// Created by Olga Shiryaeva on 10/5/19.
//
#pragma once
#include <string>
#include <iostream>
#include "student.h"

//Repository stores a collection of Books
class Roster {
private:
    int lastIndex;//index of last book in repository - so this also effectively records how many entries are currently in the repository
    int capacity;//The maximum size of the repository
    Student** classRosterArray;//books is an array of pointers to books; so, **
public:
    Roster();//empty constructor creates repository & initializes all fields to default values, like "",0,nullptr
    Roster(int capacity);//this constructor does same as above, but sets max size

    Student* getStudentAt(int index);
    void parseThenAdd(string datarow);//parses the strings, creates the Book objects, and adds them to the repository
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degree);
    void print_All();//prints all books in repository using each book's print() method
    bool remove(string studentID);//removes a book based on its ID
    void printDaysInCourse(string studentID);//Prints some book's average price
    void printInvalidEmails();//Locates and prints negative prices
    void printByDegreeProgram(int degreeProgram) ;//Prints all books of the specified type.
    ~Roster();//Destructor destroys the repository, releasing any resources it requested dynamically
};