//
// Created by Olga Shiryaeva on 10/5/19.
//
#include <iostream>
#include <iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;

Student::Student() //Empty constructor to set to default values
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->studentEmail = "";
    this->studentAge = 0;

    for (int i = 0; i < daysToCompleteSize; ++i) this->daysToCompleteCourse[i] = 0;
}

Student::Student(string Id, string fName, string lName, string email, int age, int daysToCompleteCourse[])
{
    this->studentID = Id;
    this->firstName = fName;
    this->lastName = lName;
    this->studentEmail = email;
    this->studentAge = age;

    for (int i = 0; i < daysToCompleteSize; ++i) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
}

//getters
string Student::getStudentID()
{
    return studentID;
}

string Student::getStudentFirstName()
{
    return firstName;
}

string Student::getStudentLastName()
{
    return lastName;
}

string Student::getStudentEmail()
{
    return studentEmail;
}

int Student::getStudentAge()
{
    return studentAge;
}

int * Student::getDaysToCompleteCourse()
{
    return daysToCompleteCourse;
}

//setters

void Student::setStudentID(string ID)
{
    this->studentID = ID;
}

void Student::setStudentFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setStudentLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setStudentEmail(string email)
{
    this->studentEmail = email;
}


void Student::setStudentAge(int age)
{
    this->studentAge = age;
}

void Student::setDaysToCompleteCourse(int daysToCompleteCourse[]){
    for (int i = 0; i < daysToCompleteSize; i++)
        this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
}

void Student::print()
{
    cout << left << setw(15) << studentID;
    cout << left << setw(25) << firstName;
    cout << left << setw(25) << lastName;
    cout << left << setw(25) << studentEmail;
    cout << left << setw(10) << studentAge;
    cout << left << setw(5) << daysToCompleteCourse[0];
    cout << left << setw(5) << daysToCompleteCourse[1];
    cout << left << setw(5) << daysToCompleteCourse[2];
}

Student::~Student()
{

}
