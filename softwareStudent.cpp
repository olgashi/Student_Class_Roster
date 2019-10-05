//
// Created by Olga Shiryaeva on 10/5/19.
//

SoftwareStudent::SoftwareStudent():Student()
{
    degreeType = SECURITY;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int daysToCompleteCourse[], DegreeType degreeType):Student(studentID, firstName, lastName, studentEmail, studentAge, daysToCompleteCourse)
{
    degreeType = SOFTWARE;
}

DegreeType SoftwareStudent::getDegreeType()
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