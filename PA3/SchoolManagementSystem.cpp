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

//  Default Constructor
SchoolManagementSystem::SchoolManagementSystem() 
        : courses(NULL), courseSize(0),students(NULL), studentSize(0){};

// Destructor for sms
SchoolManagementSystem::~SchoolManagementSystem()
{
    if(courses!=NULL)
    {
        delete[] courses;
        courseSize = 0;
    }
    if(students!=NULL)
    {
        delete[] students;
        studentSize = 0;
    }
}

// Returns the size of courses array
int SchoolManagementSystem::getCSize() const
{
    return courseSize;
}

// Returns the size of students array
int SchoolManagementSystem::getSSize() const
{
    return studentSize;
}

//  Lists all students in the school
void SchoolManagementSystem::listAllStudents() const
{
    for(int i=0;i<studentSize;++i)
        cout << i+1 << ". Student" << endl 
             << "Name: " << students[i]->getName() << endl
             << "ID: " << students[i]->getID() << endl;
}

//  Lists all courses in the school
void SchoolManagementSystem::listAllCourses() const
{
    for(int i=0;i<courseSize;++i)
        cout << i+1 << ". Course" << endl 
             << "Name: " << courses[i]->getName() << endl
             << "Code: " << courses[i]->getCode() << endl;
}

//  Adds student to the school
bool SchoolManagementSystem::addStudent(string name,int ID)
{
    //  Checking if there is any students with same ID
    //  Students can have same name
    if(!(studentIDChecker(ID)))
    {
        //  Creating a new student object
        Student* newStudent = new Student(name,ID);
        if(studentSize == 0)
        {
            //  Incrementing size of array by one
            ++studentSize;
            //  Creating dynamic array
            this->students = new Student*[studentSize];
            //  Adding first element
            this->students[0] = newStudent;
        }else
        {

            //  Incrementing size of array by one
            ++studentSize;

            //  Creating a temporary array to hold previous student object array
            Student **temp = new Student*[studentSize];

            //  Filling temp array
            for(int i=0;i<studentSize-1;++i)
                temp[i] = students[i];
            
            //  Adding the new student object to temp
            temp[studentSize-1] = newStudent;
            //  Deleting and reimplementing students array
            delete [] students;
            students = new Student*[studentSize];

            //  Copying temp to array
            for(int i=0;i<studentSize;++i)
                students[i] = temp[i];
            //  Deleting temp array
            delete [] temp;
        }
        //  Returning 1 when a new student has been added
        return 1;
    }
    //  Returning 0 when ID is taken by another student
    return 0;
}

//  Deletes student from school
//  Work in Progress should drop the student from every course it's taking
bool SchoolManagementSystem::deleteStudent(string name,int ID)
{
    bool flag = false;

    //  Checking if there is a student with that name and ID
    int i = studentChecker(name,ID);
    if(i==-1){

        //  studenChecker returns -1 when user wants to delete
        //  the student with the index of 0
        i=0;
        flag = true;
    }else if(i>0)
    {
        //  studentChecker returns the index value of student if the student is not the first one
        flag = true;
    }   
    //  Can't delete a non-existing student so with
    //  the default value of flag, if statement doesn't work.
    if(flag)
    {
        --studentSize;  //  Decrementing number of students by one
        Student **temp = new Student*[studentSize]; //  Reallocating a temporary array of students objects pointers
        //  Setting the values of temp array with students array
        
        
            for(int j=0;j<studentSize+1;++j)
            {
                if(j<i)
                    temp[j] = students[j];
                else if(i<j)
                    temp[j-1] = students[j]; 
                else
                {
                    for(int k=0;k<courseSize;++k)
                    {
                        //  Deletin student from every course that he/she took
                        courses[k]->deleteStudent(students[i]);
                    }
                }          
            }

            delete [] students;
            students = temp;    //  Students array gets it's values back except for deleted student
            
            //  Returning 1 if the student is deleted
            return 1;
    }

    //  Returning 0 if there are no students with that name and ID
    return 0;
}

//  Adds course to the school
bool SchoolManagementSystem::addCourse(string name,string code)
{
    if(!courseChecker(name,code))
    {
        if(courseSize == 0)
        {
            ++courseSize;
            this->courses = new Course*[courseSize];
            this->courses[0] = new Course(name,code);
        }else
        {
            ++courseSize;
            Course **temp = new Course*[courseSize];
            for(int i=0;i<courseSize-1;++i)
            {
                temp[i] = courses[i];
            }
            temp[courseSize-1] = new Course(name,code);
            delete [] courses;
            courses = temp;
        }

        return 1;
    }

    return 0;

}

//  Checks if there is a student with targeted name and ID.
//  If there is then returning it's index value in students array
int SchoolManagementSystem::studentChecker(string name,int ID)
{
    for(int i=0;i<studentSize;++i)
        if(name==this->students[i]->getName() && ID==this->students[i]->getID())
        {
            if(i==0)
            //  If the student with index=0 has the targeted name and ID
            //  Then returns -1.    
                return -1;
            else
            //  If there is a student with that name and ID and the index of
            //  the student is not zero, then returns the index value of the student.
                return i;
        } 
    //  If there are no students with that name and ID then returns 0.
    return 0;
}

//  Checks if there is a student with input ID
//  If there is then returns 1 ,if not returns 0
bool SchoolManagementSystem::studentIDChecker(int ID)
{
    for(int i=0;i<studentSize;++i)
        if(ID==this->students[i]->getID())
            return 1;
        
    return 0;
}

//  Checks if there is a course with targeted name or ID.
//  If there is then returning it's index value in students array
int SchoolManagementSystem::courseChecker(string name,string code)
{
    for(int i=0;i<courseSize;++i)
        if(name==this->courses[i]->getName() && code==this->courses[i]->getCode())
        {
            if(i==0)
            //  If the course with index=0 has the targeted name or ID
            //  Then returns -1.
                return -1;
            else
            //  If there is a course with that name and ID and the index of
            //  the course is not zero, then returns the index value of the course.
                return i;
        } 
     //  If there are no courses with that name or ID then returns 0.
    return 0;
}

//  Deletes a course from sms
//  Work in progress    Should drop the course from every student taking it 
bool SchoolManagementSystem::deleteCourse(string name,string code)
{
    bool flag = false;
    int i = courseChecker(name,code);
    if(i==-1){
        i=0;
        flag = true;
    }else if(i>0)
        flag = true;
    if(flag)
    {
        --courseSize;
        Course **temp = new Course*[courseSize];
        for(int j=0;j<courseSize+1;++j)
            {
                if(j<i)
                    temp[j] = courses[j];
                else if(i<j)
                    temp[j-1] = courses[j];
                else
                {
                    for(int k=0;k<studentSize;++k)
                    {
                        students[k]->delCourse(courses[i]);
                    }
                }
                   
            }
            delete [] courses;
            courses = temp;

            return 1;
    }
    return 0;
}

//  Adds student to a course
bool SchoolManagementSystem::addToACourse(int index,string name,int ID)
{
    bool flag = false;

    //  Taking the index value of the student
    int studentNum=studentChecker(name,ID);
    if(studentNum==-1)
    {
        //  studentChecker returns -1 if the student has 
        //  the index value of 0.
        studentNum=0;
        flag = true;
    }else if(studentNum>0 && studentNum<studentSize)
        //  studentNum will be used as the index value of students
        flag = true;
    if(flag)
    {
        if(index>=0 && index<courseSize)
        {
            //  adding the course to a student's course array
            this->students[studentNum]->addStudent(courses[index]);
            //  adding the stundent to a course's student array
            this->courses[index]->addStudent(students[studentNum]);
        }
    }
    return 0;
}

//  Lists what student is taking
void SchoolManagementSystem::listStudentCourses(string name,int ID)
{
    int i=studentChecker(name,ID);
    bool flag = false;
    if(i==-1)
    {
        flag = true;
        i = 0;
    }else if(i>0 && i<studentSize)
        flag = true;
    if(flag)
    {
        this->students[i]->print();
    }
}

//  Lists which students are taking the course
void SchoolManagementSystem::listCourseStudents(string name,string code)
{
    int i=courseChecker(name,code);
    bool flag = false;
    if(i==-1)
    {
        flag = true;
        i = 0;
    }else if(i>0 && i<courseSize)
        flag = true;
    if(flag)
    {
        this->courses[i]->print();
    }
}

//  Drops the student from course and vice versa
void SchoolManagementSystem::dropFromCourse(string name,int ID,int index)
{
    int i= studentChecker(name,ID);
    if(i==-1)
        i=0;
    students[i]->delCourse(courses[index]);
    courses[index]->deleteStudent(students[i]) ;
}

