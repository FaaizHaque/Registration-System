#include "CourseList.h"
#include <iostream>
#include <iomanip>
using namespace::std;

CourseList::CourseList()
{
    head = NULL;
}

CourseList::~CourseList()
{
    cNode * curr = head;
    while ( curr != NULL )
    {
        cNode * temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete curr;
}
void CourseList :: cancelCourse( int courseID, int studentID )
{
    cNode *temp;
    bool flag = false;
    temp = head;
    while ( temp != NULL )
    {
        if ( temp->item.getCourseID() == courseID )
            flag = true;
        temp = temp->next;
    }
    delete temp;
    if ( flag )
    {
        //One course in list
        if ( head->next == NULL )
        {
            delete head;
            head = NULL;
        }
        //Delete head with other items
        else if ( head->item.getCourseID() == courseID )
        {
            cNode * temp = head;
            head = head->next;
            delete temp;
        }

        else
        {
            cNode * curr = head->next;
            cNode * last = head;
            while ( curr->item.getCourseID() != courseID )
            {
                curr = curr->next;
                last = last->next;
            }
            //Delete last item
            if ( curr->next == NULL )
            {
                delete curr;
                last->next = NULL;
            }
            else if ( curr->next != NULL )
            {
                last->next = curr->next;
                delete curr;
            }
        }
    }
}
void CourseList :: withdrawCourse( int courseID, int studentID )
{
    cNode *temp;
    bool flag = false;
    temp = head;
    while ( temp != NULL )
    {
        if ( temp->item.getCourseID() == courseID )
            flag = true;
        temp = temp->next;
    }
    if ( flag )
    {
        //One course in list
        if ( head->next == NULL )
        {
            delete head;
            head = NULL;
        }
        //Delete head with other items
        else if ( head->item.getCourseID() == courseID )
        {
            cNode * temp = head;
            head = head->next;
            delete temp;
        }

        else
        {
            cNode * curr = head->next;
            cNode * last = head;
            while ( curr->item.getCourseID() != courseID )
            {
                curr = curr->next;
                last = last->next;
            }
            //Delete last item
            if ( curr->next == NULL )
            {
                delete curr;
                last->next = NULL;
            }
            else if ( curr->next != NULL )
            {
                last->next = curr->next;
                delete curr;
            }
        }
    }
    if ( flag )
        cout << "Student " << studentID << " has been withdrawn from course " << courseID << endl;
    else
        cout << "Student " << studentID << " is not enrolled in course " << courseID << endl;
}

bool CourseList :: checkCourse( int courseID )
{
    cNode * curr = head;
    bool flag = false;
    while ( curr != NULL )
    {
        if ( curr->item.getCourseID() == courseID )
        {
            flag = true;
        }
        curr = curr->next;
    }
    return flag;
}

void CourseList :: outputCourse( int courseID )
{
    cNode * curr = head;
    bool flag = false;
    while ( curr->item.getCourseID() != courseID )
    {
        curr = curr->next;
    }
    cout << "Course id     " <<  " Course name " << endl;
    cout << curr->item.getCourseID() << setw(16) << curr->item.getCourseTitle() << endl;
}

void CourseList :: addCourse( int courseID, string title, int studentID )
{
    cNode *temp;
    bool flag = true;
    temp = head;
    while ( temp != NULL )
    {
        if ( temp->item.getCourseID() == courseID )
            flag = false;
        temp = temp->next;
    }
    delete temp;
    if ( flag )
    {
        if ( head == NULL )
        {
            head = new cNode();
            head->item.setCourse(courseID, title);
        }
        else
        {
            cNode *curr = head->next;
            cNode *last = head;
            while ( curr != NULL )
            {
                curr = curr->next;
                last = last->next;
            }
            delete curr;
            curr = new cNode();
            curr->item.setCourse(courseID, title);
            last->next = curr;
            curr->next = NULL;
        }
    }
    if ( flag )
        cout << "Course " << courseID << " has been added to student " << studentID << endl;
    else
        cout << "Student " << studentID << " is already enrolled in course " << courseID << endl;

}

void CourseList :: display()
{
    if ( head == NULL )
    {
        return;
    }
    else
    {
        cout << "           " << "Course id    " << "Course Name     " << endl;
        cNode *  curr = head;
        while ( curr != NULL )
        {
            cout << "           ";
            cout << curr->item.getCourseID() << setw(16);
            cout << curr->item.getCourseTitle() << endl;
            curr = curr->next;
        }
        cout << endl;
    }
}
