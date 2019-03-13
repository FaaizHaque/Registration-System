#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "CourseList.h"
#include "Course.h"
using namespace::std;

class Student
{
    public:
        Student();
        virtual ~Student();
        void setStudent(string, string, int);
        void addCourse(int, string);
        void withdrawCourse(int);
        void cancelCourse(int);
        int getStudentID();
        void showStudent();
        bool checkCourse( int);
        void outputCourse(int);
        void showStudentCourse();

    protected:

    private:
        string firstName;
        string lastName;
        int id;
        CourseList courses;


};

#endif // STUDENT_H
