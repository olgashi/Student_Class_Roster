### Overview

&nbsp;&nbsp;&nbsp;The program maintains roster of students within a given course. Student data represented as an array of strings includes student ID, first name, last name, email address, age, number of days to complete each course (as an array), and degree. 
&nbsp;&nbsp;&nbsp;The program parses data supplied as an array of strings and creates students' objects using appropriate subclasses. Complete student list is stored in an array of students called _classRosterArray_. A check for invalid emails is performed and invalid emails are printed out to the console. Additionally, all provided student data is printed out to the console in a table format. Once the program is finished, the destructor is called to release memory.

### Concepts applied

&nbsp;&nbsp;&nbsp;Object-oriented programming, pointers and memory, enumerated data types, etc.

### Highlights
&nbsp;&nbsp;&nbsp;Student class is a base class that contains a set of accessor and mutator functions that are used to perform any changes to the instance variables of that class. Three subclasses of the Student class are used to create students based on their degree type. _Roster_ class uses array of pointers to hold provided student data. The program’s functionality includes: checking for invalid emails, printing average days in course for each student, printing all students, removing a student with a particular ID#.