#ifndef SCHOOLManagementSYSTEM_H
#define SCHOOLManagementSYSTEM_H
#include <stdio.h>

#include "Student.h"
#include "Course.h"

using namespace std;

class SchoolManagementSystem
{
    public:
    SchoolManagementSystem();

    ~SchoolManagementSystem();

    int getCSize() const;

    int getSSize() const;

    void listAllStudents() const;

    void listAllCourses() const;

    bool addStudent(string name,int ID);

    bool addCourse(string name,string code);
    
    bool deleteStudent(string name,int ID);

    bool deleteCourse(string name,string code);

    int studentChecker(string name,int ID);

    bool studentIDChecker(int ID);

    int courseChecker(string name,string code);

    bool addToACourse(int index,string name,int ID);

    void listStudentCourses(string name,int ID);

    void listCourseStudents(string name,string code);

    void dropFromCourse(string name,int ID,int index);

    private:
    Course** courses;
    Student** students;
    int courseSize;
    int studentSize;
};

#endif