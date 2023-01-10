#include <iostream>
#include <string>

#include "Student.h"


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

//  Default Constructor
Course::Course()
                :name(""),code("") ,size(0){}

//  Second Constructor
Course::Course(string& name,string& code)
{
    //  Setting the name and code
    this->name = name;
    this->code = code;
}
//  Deconstructor
Course::~Course()
{
    //  Deletes the array of students array
    delete [] students;
}

//  Returns the name of the course
string Course::getName() 
{
    return name;
}

//  Returns the code of the course
string Course::getCode() 
{
    return code;
}

//  Sets the name of the course
void Course::setName(const string& name)
{
    this->name = name;
}

//  Sets the code of the course
void Course::setCode(const string& code)
{
    this->code = code;
}

//  Lists which students are takin the course
void Course::print()
{
    for(int i=0;i<size;++i)
        cout << i+1 << ". Student" << endl
             << "Name: " << students[i]->getName() << endl
             << "ID: " << students[i]->getID() << endl;
    
}

//  Adds a student to the course
void Course::addStudent(Student* student)
{
    if(studentChecker(student)) //  Checks if the course has the student or not
    {
        if(size == 0)
        {
            ++size;     //  Increasing the number of students by one
            this->students = new Student*[size];    //  Allocating memory for students array
            this->students[0] = student;    //  Adding the student to students array
        }else
        {
            ++size;     //  Increasing the number of students by one
            Student **temp = new Student*[size];    //  Allocating memory for temporary array so it can save the students array
            for(int i=0;i<size-1;++i)
                temp[i] = students[i];      //  Copying students array
            
            temp[size-1] = student;     //  Adding the new student to temp array
            delete [] students;     //  Deleting students array
            students = new Student*[size];      //  Reallocating memory for students array
            for(int i=0;i<size;++i)
                students[i] = temp[i];  //  Copying temp array to students array
            delete [] temp;     //  Deletin temp array
        }
    }
}

//  Checks if the course has that student or  not
//  Returns 0 if it has
//  Returns 1 if not
bool Course::studentChecker(Student* student)
{
    for(int i=0;i<size;++i)
        if(student->getID()==this->students[i]->getID())
            return 0;
    return 1;
}

//  Deletes student from course 
void Course::deleteStudent(Student* student)
{
    for(int i=0;i<size;++i)
        if(students[i]->getID() == student->getID() && students[i]->getName() == student->getName())
        {
            --size;     //  Decrementing size of course
            Student **temp = new Student*[size];        //  Allocating memory for temporary array
            for(int j=0;j<size;++j)     //  Copying values to temp array except for that student
            {
                if(j<i)
                    temp[j] = students[j];
                else if(i<j)
                    temp[j-1] = students[j];
            }
            delete [] students;     // Deleting students array
            students = temp;        //  Copying and deleting temp array
            delete [] temp ;
        }
}