#include <iostream>
#include <string>
#include <cstdlib>
#include "SchoolManagementSystem.h"


using namespace std;

//  This is called when user enters 1 in the main menu
//  This function can call addStudent and/or selectedStudent
//  submenus.
void StudentMenu(SchoolManagementSystem* school);

//  Adds a student to school object
void addStudent(SchoolManagementSystem* school);

//  This is the second submenu of student menu
//  This is allowed to be called if there is a student in the system
//  and user enters a valid student name and ID.
void SelectedStudent(SchoolManagementSystem* school,string name,int ID);

//  This is called when user enters 2 in the main menu
//  This function can call addCourse and/or selectedCourse
//  submenus.
void CourseMenu(SchoolManagementSystem* school);

//  Adds a course to school object
void addCourse(SchoolManagementSystem* school);

//  This is the second submenu of course menu
//  This is allowed to be called if there is a course in the system
//  and user enters a valid course name and code.
void selectedCourse(SchoolManagementSystem* school,string name,string code);

int main()
{
    SchoolManagementSystem* school = new SchoolManagementSystem;
    cout << "Main Menu" << endl;
    do
    {
        int input = 0;
        cout << "0 exit" << endl
             << "1 student" << endl
             << "2 course" << endl
             << "3 list_all_students" << endl
             << "4 list_all_courses" << endl;
        cin >> input;
        if(input == 1)
        {
            StudentMenu(school);
        }else if(input == 2)
        {
            CourseMenu(school);
        }else if(input == 3)
        {
            school->listAllStudents();
        }else if(input == 4)
        {
            school->listAllCourses();      
        }else
            break;
        
    }while (1);
    
}

//  This is called when user enters 1 in the main menu
//  This function can call addStudent and/or selectedStudent
//  submenus.
void StudentMenu(SchoolManagementSystem* school)
{
    int input;
    cout << "0 up" << endl
         << "1 add student" << endl
         << "2 select_student" << endl;
    cin >> input;
    if(input == 0)
    {
        // exits to main menu
        return ;
    }else if(input == 1)
    {
        addStudent(school);
    }else if(input == 2 && school->getSSize()!=0)
    {
        string name;
        int ID;
        cout << "Name:";
        cin >> name;
        cout << "ID:";
        cin >> ID;
        if(abs(school->studentChecker(name,ID)))
            SelectedStudent(school,name,ID);
    }
    return ;
}

//  Adds a student to school object
void addStudent(SchoolManagementSystem* school)
{
    string name;
    int ID;

    // Taking input from user
    cout << "Name:";
    cin >> name;
    cout << "ID:";
    cin >> ID;

    //  Checking if there is a student with the same id.
    //  If not adding to the system.
    if(!(school->addStudent(name,ID)))
    {
        cout << "Couldn't add student because id is being used by another student." << endl; // Delete this debug line
    }else
    {
        cout << "Successfully added the student." << endl;  // Delete this debug line
    }
}

//  This is the second submenu of student menu
//  This is allowed to be called if there is a student in the system
//  and user enters a valid student name and ID.
void SelectedStudent(SchoolManagementSystem* school,string name,int ID)
{
    // Taking input from user
    int input = 0;
    cout << "0 up" << endl
         << "1 delete_student" << endl
         << "2 list courses" << endl
         << "3 add_selected_student_to_a_course" << endl
         << "4 drop_selected_student_from_a_course" << endl;;
    cin >> input;
    if(input == 0 )
    {
        // Going to main menu
        return ;
    }else if(input == 1)
    {
        //  Deleting the student from system
        school->deleteStudent(name,ID); 
        return ;
    }else if(input == 3 && school->getCSize() !=0)
    {
        //  Listing all courses so the user can pick one
        school->listAllCourses();  
        cin >> input;

        //  Sending the name and ID of the selected student
        //  also sending the input after decrementing it
        //  because it's going to be an index value.
        //  If student is not taking that course then
        //  adding him/her to that course.
        school->addToACourse(--input,name,ID);
        return ;
    }else if(input == 4 && school->getCSize() !=0)
    {
        //  Listing all courses so the user can pick one
        school->listAllCourses();   
        cin >> input;

        //  Sending the name and ID of the selected student
        //  also sending the input after decrementing it
        //  because it's going to be an index value.
        //  If student is taking that course then
        //  dropping him/her from that course.
        school->dropFromCourse(name,ID,--input);
        return ;
    }else{
        //  Returning to main menu if the input is invalid.
        return ;
    }
}

//  This is called when user enters 2 in the main menu
//  This function can call addCourse and/or selectedCourse
//  submenus.
void CourseMenu(SchoolManagementSystem* school)
{
    int input = 0;
    string code;
    string name;

    cout << "0 up" << endl
         << "1 add_course" << endl
         << "2 select_course" << endl;
    cin >> input;

    if(input == 0)
    {
        return ;
    }else if(input == 1)
    {
        addCourse(school);
    }else if(input == 2)
    {
    
        //  Taking new course's name and code from user  
        cout << "Course Code and Name:" ;
        cin >> code;
        getline(cin,name,' ');
        getline(cin,name,'\n');
        if(abs(school->courseChecker(name,code)))
            selectedCourse(school,name,code);
        
    }else
    {
        cout << "Invalid Input" << endl; // Delete  this debug line
        return;
    }
}

//  Adds a course to school object
void addCourse(SchoolManagementSystem* school)
{
    string code,name;
    //  Taking new course's name and code from user
    cout << "Course Code and Name:" ;
    cin >> code;
    getline(cin,name,' ');
    getline(cin,name,'\n');

    //  Checking if there is any courses with same name or code
    //  If not, then adding to the system
    if(school->addCourse(name,code))
    {
        cout << "Successfully added the course." << endl;   // Delete this debug line
    }else
    {
        cout << "Couldn't add the course because code or name is already taken by another course." << endl; // Delete this debug line
    }
}

//  This is the second submenu of course menu
//  This is allowed to be called if there is a course in the system
//  and user enters a valid course name and code.
void selectedCourse(SchoolManagementSystem* school,string name,string code)
{
    int input;
    cout << "0 up" << endl
         << "1 delete_course" << endl
         << "2 list_students_registered_to_the_selected_course" << endl;
    cin >> input;

    if(input == 0)
    {
        //  Going to upper menu
        CourseMenu(school);
    }else if(input == 1)
    {
        //  Deleting a course if the input is valid
        school->deleteCourse(name,code);      
    }else if(input == 2)
    {
        //  Listing all students registered to that course
        school->listCourseStudents(name,code);  
    }else
    {
        cout << "Invalid input" << endl; // Delete this debug line
        return ;
    }
}