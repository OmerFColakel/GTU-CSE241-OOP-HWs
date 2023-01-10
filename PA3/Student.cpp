#include <iostream>
#include <string>

#include "Course.h"

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

//  Default Constructor
Student::Student() : name(""), ID(0),courses(NULL){}

//  Second Constructor
//  Sets the values of name,ID and size
Student::Student( string name, int ID)
{
    this->name = name;
    this->ID = ID;
    this->size = 0;
}

//  Destructor
Student::~Student()
{
    delete [] courses;
    size = 0;
}

//  Setter for ID
void Student::setID(int ID)
{
    this->ID = ID;
}

//  Setter for the name
void Student::setName(string name)
{
    this->name = name;
}

//  Getter for name
string Student::getName() const
{
    return name;
}

//  Getter for ID
int Student::getID() const
{
    return ID;
}

//  Getter for ID
int Student::getSize() const
{
    return size;
}

//  Setter for size
void Student::setSize(int size)
{
    this->size = size;
}

//  Prints the courses taken by the student
void Student::print()
{
    for(int i=0;i<size;++i)
        cout << i+1 << ". Course" << endl
             << "Name:" << courses[i]->getName() << endl
             << "Code:" << courses[i]->getCode() << endl;
}

//  Adding the course to the student's list
void Student::addStudent(Course* course)
{
    
    if(courseChecker(course))   //  Checks if the student is taking the course or not
    {
        if(size == 0)
        {
            ++size;     //  Incremeting size of array           
            this->courses = new Course*[size];      //  Allocating memory for courses array
            this->courses[0] = course;      //  Adding the first element of courses
        }else
        {
            ++size;     //  Incremeting size of array
            Course **temp = new Course*[size];      //  Allocating memory for temporary array
            for(int i=0;i<size-1;++i)
                temp[i] = courses[i];   //  Setting the values of temp array so it can be recovered later
                     
            temp[size-1] = course;    //  Adding the new element to temp array
            delete [] courses;  //  Deleting courses array
            courses = new Course*[size];    //  Reallocating memory for courses array
            for(int i=0;i<size;++i)     //  Setting the values of courses
                courses[i] = temp[i];
            delete [] temp;     //      Deleting temp array
        }
    }
}

//  Checks if the student is taking the course or not
//  If it's taking then returning 0
//  If not then returning 1
bool Student::courseChecker(Course* course)
{
    for(int i=0;i<size;++i)
        if(course->getCode()==this->courses[i]->getCode() && course->getName()==this->courses[i]->getName() )
            return 0;
    return 1;
}

//  Drops the student from the course
//  Work in progress
void Student::delCourse(Course* course)
{
    for(int i=0;i<size;++i)
        if(courses[i]->getName() ==  course->getName() && courses[i]->getCode() == course->getCode())
        {
            --size;     //  Decrementing the size of students array
            Course **temp = new Course*[size];      //  Allocating memory to temp course pointer array
            for(int j=0;j<size+1;++j)       //  Copying courses array to temp array
            {
                if(j<i)
                    temp[j] = courses[j];
                else if(i<j)
                    temp[j-1] = courses[j];
            }
            delete [] courses;      // Deleting courses array
            courses = temp;     //  Copying temp array to courses array
            delete [] temp ;        //  Deleting temp array
        }

}