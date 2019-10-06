//
// Created by Olga Shiryaeva on 10/5/19.
//
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
using std::cout;
using std::cerr;
//ALWAYS DEFINE THE EMPTY CONSTRUCTOR - IT GETS CALLED BY DEFAULT IF NO OTHER SPECIFIED!
Roster::Roster()//The empty constructor sets to default values
{
    this->capacity = 0;
    this->lastIndex = -1;//Means EMPTY; 0 is a valid index in an array
    this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)//Sets a max capacity for the repository
{
    this->capacity = capacity;
    this->lastIndex = -1;//AGAIN; means empty
    this->classRosterArray = new Student*[capacity];
}

Student * Roster::getStudentAt(int index)
{
    return classRosterArray[index];
}

//modified 12/17/2018
//Calls a separate add() method at the end
void Roster::parseThenAdd(string row)
{
    if (lastIndex < capacity) {
        lastIndex++;
        DegreeType degreeType;
        //Test if fiction or nonfiction - cannot create anything of type 'Book'
        //Note this is a big fat cheat - first letter of ID is always F or N     ;-) (wink)
        if (row[0] == 'N') degreeType = NETWORKING;
        else if ((row[0] == 'S') && (row[1] == 'E'))degreeType = SECURITY;
        else if ((row[0] == 'S') && (row[1] == 'O'))degreeType = SOFTWARE;
        else //barf and leave
        {
            cerr << "INVALID STUDENT TYPE!  EXITING NOW!\n";
            exit(-1);
        }

        //We will parse through each 'book string' delimiting on the COMMA
        //We will then extract each substring and store them in temp variables
        //Get the ID, assign it to a temporary holding variable
        int rhs = row.find(",");
        string sID = row.substr(0, rhs);

        //read title
        int lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sFirstName = row.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sLastName = row.substr(lhs, rhs - lhs);

        //read author
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        string sEmail = row.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int sAge = stod(row.substr(lhs, rhs - lhs));

        //read each price
        //NOTE THAT EACH PRICE MUST BE CONVERTED TO A DOUBLE
        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int days1 = stoi(row.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int days2 = stoi(row.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = row.find(",", lhs);
        int days3 = stoi(row.substr(lhs, rhs - lhs));

        //NOW JAM THE INFO IN HERE - NOTE add() WANTS THE PRICES INDIVIDUALLY, NOT AS AN ARRAY
        //The add() method will create the Fiction or Nonfiction book
        add(sID, sFirstName, sLastName, sEmail, sAge, days1, days2, days3, degreeType);
    }
    else //barf and leave - we have exceeded capacity
    {
        cerr << "ERROR! LIST HAS EXCEEDED MAXIMUM CAPACITY!\n EXITING NOW!";
        exit(-1);
    }
}

//This method creates the book of proper type, then adds to repository - all parsed values passed in
void Roster::add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int days1, int days2, int days3, DegreeType sd)
{
    //Make an array to get the prices into the constructor, mkay?
    int studentCourses[Student::daysToCompleteSize];//That's why this is public in Book class
    studentCourses[0] = days1;
    studentCourses[1] = days2;
    studentCourses[2] = days3;
    if (sd == SOFTWARE) classRosterArray[lastIndex] = new SoftwareStudent(sID,sFirstName, sLastName, sEmail, sAge, studentCourses, sd);
    else if (sd == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(sID,sFirstName, sLastName, sEmail, sAge, studentCourses, sd);
    else classRosterArray[lastIndex] = new NetworkStudent(sID,sFirstName, sLastName, sEmail, sAge, studentCourses, sd);
}

void Roster::print_All()//Roll thru the array of books and call print method for each one
{
    //Note this works properly for BOTH fiction and nonfiction books; that's run-time polymorphism!
    for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

bool Roster::remove(string ID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == ID) //Book found
        {
            found = true;
            //delete it
            delete this->classRosterArray[i];
            //Move last book to this position - no gaps in array
            //This might be self-assignment, but poses no danger
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--;//Roster is one element smaller
        }
    }
    return found;
}

void Roster::printDaysInCourse(string studentID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getStudentID() == studentID) //Book found
        {
            found = true;
            int* p = classRosterArray[i]->getDaysToCompleteCourse();
            cout << "Average price of book " << studentID << " is " << (p[0] + p[1] + p[2]) / 3 << "\n";
        }
    }
    if (!found) cout << "Student not found!\n";
}

//modified 20181030
void Roster::printInvalidEmails()
{
    cout << "Displaying invalid price entries:\n";
    bool any = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        any = false;
        string p = classRosterArray[i]->getStudentEmail();
        for (int j = 0; j < Student::daysToCompleteSize; j++)
        {
            if (p[j]<0)
            {
                any = true;
                cout << "Student ID " << classRosterArray[i]->getStudentID() << ": ";
                cout << p[j] << " ";
            }
        }
        if (any) cout << "\n";
    }
    if (!any) cout << "NONE";
}

void Roster::printByDegreeProgram(int degreeProgram)
{
    cout << "Printing students of type " << degreeTypeStrings[degreeProgram] << "\n";
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) this->classRosterArray[i]->print();
    }
}

Roster::~Roster()//destroys all the books
{
    for (int i = 0; i <= lastIndex; i++)
    {
        delete this->classRosterArray[i];//Deletes each book first
    }
    delete classRosterArray;//Deletes the dynamically allocated array of pointers to the books
}

int main() //MAIN - HERE WE GO
{
    //modified 12/17/2018
    int numStudents = 5;
    //Input is 6 long comma-delimited strings
    const string studentData[] =
            {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
             "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
             "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
             "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
             "A5,Olga,Shiryaeva,oshiryaeva@wgu.edu,35,30,22,30,SOFTWARE"};

    Roster * rep = new Roster(numStudents);//MAKE THE REPOSITORY
    cout << "Parsing data and adding students:\t";
    for (int i = 0; i < numStudents; i++)
    {
        rep->parseThenAdd(studentData[i]);//PARSE EACH LINE, TURN THEM INTO BOOKS, AND ADD THEM TO REPOSITORY
    }
    cout << "DONE.\n";
    cout << "Displaying all students:\n";
    rep->print_All();//DISPLAY ALL BOOKS IN THE REPOSITORY

    cout << "Removing F4:\n";//REMOVE BOOK WITH THE SUPPLIED ID
    if (rep->remove("F4")) {
        rep->print_All();
        numStudents--;
    }
    else cout << "Student not found!\n";

    cout << "Removing F4:\n";//REMOVE SAME ITEM TWICE TO CHECK ERROR CONDITION
//    if (rep->remove("F4")) {
//        rep->print_All();
//    }
//    else cout << "Student not found!\n";

    cout << "Printing average days for all students:\n";
//    for (int i = 0; i < numStudents; i++) {
//        rep->printDaysInCourse(rep->getStudentAt(i)->getStudentID());//PRINTS THE AVERAGE PRICE OF SPECIFIED BOOK
//    }
    // rep->printInvalidEmails();//SPOTS PRICES THAT ARE IN ERROR AND DISPLAYS THEM

    //Now we will only print books of the specified types
    //Note index is casted from an integer to a BookType enum
//    for (int i = 0; i < 2; i++) rep->printByDegreeProgram((DegreeType) i);

    system("pause");//NEEDED ONLY TO HOLD CONSOLE WINDOW UP IF USING VSTUDIO
    return 0;//ALL DONE; BYE-BYE!
}
