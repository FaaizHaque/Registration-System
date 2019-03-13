#ifndef REGISTRATIONSYSTEM_H
#define REGISTRATIONSYSTEM_H
#include <string>
#include "Student.h"
using namespace::std;

class RegistrationSystem
{
    public:
        RegistrationSystem();
        ~RegistrationSystem();
        void addStudent( const int studentId, const string firstName, const string lastName );
        void deleteStudent( const int studentId );
        void addCourse( const int studentId, const int courseId, const string courseName );
        void withdrawCourse( const int studentId, const int courseId );
        void cancelCourse( const int courseId );
        void showStudent( const int studentId );
        void showCourse( const int courseId );
        void showAllStudents();

    private:
        int sizeOfList;
        struct sNode
        {
            Student item;
            sNode *next;
            sNode *prev;
        };
        sNode *head;

};

#endif // REGISTRATIONSYSTEM_H
