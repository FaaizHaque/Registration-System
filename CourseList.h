#ifndef COURSELIST_H
#define COURSELIST_H
#include "Course.h"

class CourseList
{
    public:
        CourseList();
        virtual ~CourseList();
        void addCourse( int, string, int );
        void withdrawCourse( int , int );
        void display();
        bool checkCourse(int);
        void outputCourse(int);
        void cancelCourse(int, int );

    protected:

    private:

        struct cNode
        {
            Course item;
            cNode *next;
        };
        cNode *head;
};

#endif // COURSELIST_H
