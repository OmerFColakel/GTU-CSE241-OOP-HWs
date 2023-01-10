#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>

class Student;
using namespace std;

class Course
{
    public:
    // Default Constructor
    Course();
    // Copy Constructor
    Course(string& name,string& code);

    ~Course();

    //  Returns the name of the course
    string getName() ;

    //  Returns the code of the course
    string getCode() ;

    //  Sets the name of the course
    void setName(const string& name);

    //  Sets the code of the course
    void setCode(const string& code);

    //  Lists the students taking the course
    void print();

    //  Adds a student to the course
    void addStudent(Student* student);

    //  Deletes student from course
    void deleteStudent(Student* student);

    private:

    //  Checks if the student is already taking the course or not
    bool studentChecker(Student* student);
    Student** students;
    string name;
    string code;
    int size=0;
};

#endif