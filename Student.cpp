#include "Student.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "CourseList.h"
using namespace::std;

Student::Student()
{
}

Student::~Student()
{
}

void Student :: addCourse(int courseID, string title )
{
    courses.addCourse(courseID, title, id);
}

bool Student :: checkCourse( int courseID )
{
    return ( courses.checkCourse(courseID) );
}

void Student :: withdrawCourse( int courseID )
{
    courses.withdrawCourse(courseID, id);
}

void Student :: cancelCourse( int courseID )
{
    courses.cancelCourse(courseID, id );
}

void Student :: outputCourse( int courseID )
{
    courses.outputCourse(courseID);
}
void Student :: setStudent( string first, string last, int num )
{
    id = num;
    firstName = first;
    lastName = last;
}

int Student :: getStudentID()
{
    return id;
}

void Student :: showStudentCourse()
{
    cout << "          " <<  id << setw(16) << firstName << setw(12) << "     " << lastName << endl;
}
void Student :: showStudent()
{
    cout << id << setw(16) << firstName << setw(12) << "     " << lastName << endl;
    courses.display();

}
