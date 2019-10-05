//
// Created by Olga Shiryaeva on 10/5/19.
//

NetworkStudent::NetworkStudent():Student()
{
    degreeType = SECURITY;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToCompleteCourse[], DegreeType degreeType):Student(studentID, firstName, lastName, studentEmail, studentAge, daysToCompleteCourse)
{
    degreeType = NETWORK;
}

DegreeType NetworkStudent::getDegreeType()
{
    return NETWORK;
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