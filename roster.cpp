//
// Created by Olga Shiryaeva on 10/5/19.
//
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <regex>
#include <iomanip>

using namespace std;
Roster::Roster()//The empty constructor sets to default values
{
    this->capacity = 0;
    this->lastIndex = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)// capacity to set a capacity for the repository
{
    this->capacity = capacity;
    this->lastIndex = -1;
    this->classRosterArray = new Student*[capacity];
}

Student * Roster::getStudentAt(int index) 
{
    return classRosterArray[index];
}

void Roster::parseThenAdd(string row){
    if (lastIndex < capacity) {
        lastIndex++;
        DegreeType degreeType;
        vector<string> results;
        // to parse each student record
        for (auto words : row) {
            stringstream  ss(row);
            string studentRecord;
            while (getline(ss, studentRecord, ',')) {
                results.push_back(studentRecord);
            }
        }
    
        string sID = results[0];
        string sFirstName = results[1];
        string sLastName = results[2];
        string sEmail = results[3];
        int sAge = stoi(results[4]);
        int days1 = stoi(results[5]);
        int days2 = stoi(results[6]);
        int days3 = stoi(results[7]);
		// assign student degree type
        if (results[8][0] == 'N') degreeType = NETWORKING;
        else if ((results[8][0] == 'S') && (results[8][1] == 'E'))degreeType = SECURITY;
        else if ((results[8][0] == 'S') && (results[8][1] == 'O'))degreeType = SOFTWARE;
        else
        {
            cerr << "Invalid student type. Exiting the program...\n";
            exit(-1);
        }
		// add student to student roster
         add(sID, sFirstName, sLastName, sEmail, sAge, days1, days2, days3, degreeType);
    }
    else 
    {
        cerr << "List has exceeded capacity. Exiting the program...";
        exit(-1);
    }
}

// Creates the student with correct degree type, adds to roster
void Roster::add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int days1, int days2, int days3, DegreeType sd)
{
    int studentCourses[Student::daysToCompleteSize];
    studentCourses[0] = days1;
    studentCourses[1] = days2;
    studentCourses[2] = days3;
    if (sd == SOFTWARE) classRosterArray[lastIndex] = new SoftwareStudent(sID,sFirstName, sLastName, sEmail, sAge, studentCourses, sd);
    else if (sd == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(sID,sFirstName, sLastName, sEmail, sAge, studentCourses, sd);
    else classRosterArray[lastIndex] = new NetworkStudent(sID,sFirstName, sLastName, sEmail, sAge, studentCourses, sd);
}
// Print all students
void Roster::printAll()
{
    for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}
// Remove student with given ID
bool Roster::remove(string ID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == ID)
        {
			found = true;
            delete this->classRosterArray[i];
            
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--;
        }
    }
    return found;
}
// Print average days in course for a student
void Roster::printAverageDaysInCourse(string studentID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == studentID)
        {
            found = true;
            int* p = classRosterArray[i]->getDaysToCompleteCourse();
            cout << "Average days in course for student with ID# " << studentID << " is " << (p[0] + p[1] + p[2]) / 3 << ".\n";
        }
    }
    if (!found) cout << "Student not found!\n";
}
// Print invalid emails
void Roster::printInvalidEmails()
{
    const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    bool any = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        string p = classRosterArray[i]->getStudentEmail();
        if (!regex_match(p, pattern)) {
            any = true;
            cout << p <<"\n";
        }
    }
    if (!any) cout << "There are no invalid emails.";
}
// Print students by degree program
void Roster::printByDegreeProgram(int degreeProgram)
{
    cout << "Printing students of type " << degreeTypeStrings[degreeProgram] << "\n";
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) this->classRosterArray[i]->print();
    }
}


Roster::~Roster()// Destroys all students
{
    for (int i = 0; i <= lastIndex; i++)
    {
        delete this->classRosterArray[i];
    }
    delete classRosterArray;
	cout << "\nDestructor is executed\n";
}

int main() //  Main
{
    int numStudents = 5;
    
	// Input is 5 long comma-delimited strings containing student data
    const string studentData[] =
            {"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
             "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
             "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
             "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
             "A5,Olga,Shiryaeva,oshirya@wgu.edu,35,30,22,30,SOFTWARE"};

    Roster * classRoster = new Roster(numStudents); // Create student roster
    cout << "Parsing student data and adding students to roster:\t";
    for (int i = 0; i < numStudents; i++)
    {
        classRoster->parseThenAdd(studentData[i]);// Parses each record, creates a student, adds to roster
    }
    cout << "Finished parsing and adding.\n";

    cout << "Displaying all students:\n";
	cout << left << setw(10) << "\nStudent ID    First Name                Last Name                 Email                  Age       Days in Course    Degree   \n";
	cout << left << setw(5) << "---------------------------------------------------------------------------------------------------------------------------------\n";
	
    classRoster->printAll();// Print all students in roster

	cout << "\nDisplaying invalid emails:\n";
	classRoster->printInvalidEmails();// Print emails that have invalid format

	cout << "\nPrinting average days in course for all students:\n";
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i)->getStudentID());// Print average days in course for each student
	}

	// Print students of provided Degree type
	cout << left << setw(10) << "\nStudent ID    First Name                Last Name                 Email                  Age       Days in Course    Degree   \n";
	cout << left << setw(5) << "---------------------------------------------------------------------------------------------------------------------------------\n";
	classRoster->printByDegreeProgram(SOFTWARE);

    cout << "\nRemoving student with ID# A3. Then printing remaining students in the roster. Then trying to remove the same student again to check error conditions.\n";
	// Remove student with provided ID twice: first - to remove, second - to check error condition
	for (int i = 0; i < 2; i++) {
		if (classRoster->remove("A3")) {
			cout << left << setw(10) << "Student ID    First Name                Last Name                 Email                  Age       Days in Course    Degree   \n";
			cout << left << setw(5) << "---------------------------------------------------------------------------------------------------------------------------------\n";
			classRoster->printAll();
			numStudents--;
		}
		else cout << "\nStudent not found!\n";
	}

	classRoster->~Roster();

    return 0;
}
