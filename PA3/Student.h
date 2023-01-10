#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Course;

using namespace std;

class Student
{
    public:
    Student();
    // Copy Constructor
    Student(string name,int ID);

    //  Deconstructor
    ~Student();

    // Returns ID of the student
    int getID() const;

    //  Returns name of the student
    string getName() const;

    //  Sets the name of the student
    void setName(string name);
    
    //  Sets the ID of the student
    void setID(int ID);

    //  Adds a course to the student
    void addStudent(Course* course);

    //  Drops a course from the student
    void delCourse(Course* course);

    //  Returns the size of the course array
    int getSize() const;
    
    //  Sets the size of the array
    void setSize(int size);

    //  Prints which courses are being taken by the student
    void print();

    private:
    
    bool courseChecker(Course* course);
    Course** courses;
    string name;
    int ID;
    int size=0;
};

#endif