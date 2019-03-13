#include "RegistrationSystem.h"
#include <string>
#include <iostream>
using namespace::std;

RegistrationSystem::RegistrationSystem()
{
    head = NULL;
}

RegistrationSystem::~RegistrationSystem()
{
    sNode * curr = head;
    while ( curr != NULL )
    {
        sNode * temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete curr;
}

void RegistrationSystem:: addStudent( int id, string first, string last )
{
    //Checks if student exists and updates a flag checker accordingly
    bool flag = true;
    sNode * curr = head;
    while ( curr != NULL )
    {
        if ( curr->item.getStudentID() == id )
            flag = false;
        curr = curr->next;
    }

    if ( flag )
    {
        //Case for empty list
        sNode * newPtr = new sNode();
        newPtr->item.setStudent( first, last, id );
        if ( head == NULL )
        {
            head = newPtr;
            head->next = NULL;
            head->prev = NULL;
        }

        //Case for one element in list, and to add after head
        else if ( head->next == NULL && head->item.getStudentID() < id )
        {
            head->next = newPtr;
            newPtr->prev = head;
            newPtr->next = NULL;
        }

        //Case to add to head
        else if ( head->item.getStudentID() > id )
        {
            head->prev = newPtr;
            newPtr->next = head;
            head->next = NULL;
            head = newPtr;
        }

        //All other cases to add to a sorted ascending list based on ID
        else
        {
            sNode * curr = head->next;
            sNode * last = head;
            while ( curr != NULL && curr->item.getStudentID() < id )
            {
                curr = curr->next;
                last = last->next;
            }
            //Case 1: Curr is NULL, so we add to the end of the list
            if ( curr == NULL )
            {
                curr = newPtr;
                newPtr->prev = last;
                last->next = newPtr;
                newPtr->next = NULL;
            }
            //Case 2: Curr points to a node with an ID greater than given ID, so the node must be placed before curr
            else
            {
                last->next = newPtr;
                newPtr->prev = last;
                newPtr->next = curr;
            }
        }

        cout << "Student " << id << " has been added " << endl;
    }
    else
    {
        cout << "Student " << id << " already exists" << endl;
    }
}

void RegistrationSystem :: addCourse( int studentID, int courseID, string courseName )
{
    sNode * curr = head;
    bool flag = false;
    while ( curr != NULL )
    {
        if ( curr->item.getStudentID() == studentID )
        {
            curr->item.addCourse( courseID, courseName );
            flag = true;
        }
        curr = curr->next;
    }
    if ( !flag )
        cout << "Student " << studentID << " does not exist " << endl;
}

void RegistrationSystem :: withdrawCourse( int studentID, int courseID )
{
    sNode * curr = head;
    bool flag = false;
    while ( curr != NULL )
    {
        if ( curr->item.getStudentID() == studentID )
        {
            curr->item.withdrawCourse( courseID );
            flag = true;
        }
        curr = curr->next;
    }
    if ( !flag )
        cout << "Student " << studentID << " does not exist " << endl;
}

void RegistrationSystem :: showStudent( int studentID )
{
    sNode * curr = head;
    bool flag = false;
    while ( curr != NULL )
    {
        if ( curr->item.getStudentID() == studentID )
        {
            flag = true;
            cout << "Student id     " << "First name     " << "Last Name " << endl;
            curr->item.showStudent();
        }
        curr = curr->next;
    }
    if ( !flag )
        cout << "Student " << studentID << " does not exist " << endl;
}

void RegistrationSystem :: showAllStudents()
{
    sNode * curr = head;
    if ( head == NULL )
        cout << " There are no students in the system " << endl;
    else
    {
        cout << "Student id     " << "First name     " << "Last Name " << endl;
        while ( curr != NULL )
        {
            curr->item.showStudent();
            curr=curr->next;
        }

    }
}

void RegistrationSystem :: showCourse( int courseID )
{
    sNode * curr = head;
    if ( head == NULL )
        cout << "Course " << courseID << " does not exist " << endl;
    else
    {
        while (  curr != NULL && !curr->item.checkCourse(courseID)  )
        {
            curr = curr->next;
        }

        if ( curr != NULL  )
        {
            curr->item.outputCourse( courseID );
            curr = head;
            cout << "          " <<  "Student id     " << "First name     " << "Last Name " << endl;
            while ( curr != NULL )
            {
                if ( curr->item.checkCourse(courseID) )
                {
                    curr->item.showStudentCourse();
                }

                curr = curr->next;
            }

        }
        else if ( curr == NULL )
            cout << "Course " << courseID << " does not exist" << endl;
    }

}
void RegistrationSystem :: cancelCourse( int courseID )
{
    sNode * curr = head;
    bool flag = false;
    while ( curr != NULL )
    {
        if ( curr->item.checkCourse(courseID) )
        {
            flag = true;
            curr->item.cancelCourse(courseID);
        }
        curr = curr->next;
    }
    if ( flag )
        cout << "Course " << courseID << " has been canceled" << endl;
    else
        cout << "Course " << courseID << " does not exist " << endl;
}

void RegistrationSystem :: deleteStudent( int studentID )
{
    bool flag = false;
    sNode * curr = head;
    while ( curr != NULL )
    {
        if ( curr->item.getStudentID() == studentID )
            flag = true;
        curr = curr->next;
    }

    if ( flag )
    {
        //Case 1: Head is only item and it needs to be deleted
        if ( head->item.getStudentID() == studentID && head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        //Case 2: Head needs to be deleted but its not the only item
        else if ( head->item.getStudentID() == studentID && head->next != NULL )
        {
            sNode * temp = head;
            head =  head->next;
            head->prev = NULL;
            delete temp;
        }
        //Case 3: Two items but the last item needs to be deleted
        else if ( head->next->item.getStudentID() == studentID && head->next->next == NULL )
        {
            head->next->prev = NULL;
            delete head->next;
            head->next = NULL;
        }
        else
        {
            curr = head->next;
            sNode * last = head;
            while ( curr->item.getStudentID() != studentID )
            {
                curr = curr->next;
                last = last->next;

            }
            //Case where curr->next is null, so curr is last item
            if ( curr->next == NULL )
            {
                last->next = NULL;
                delete curr;
            }
            //Case where curr is nor the last item nor the head
            else if ( curr->next != NULL )
            {
                sNode * temp = curr;
                last->next = curr->next;
                curr->next->prev = last;
                delete temp;
            }
        }
    }

    if ( flag )
        cout << "Student " << studentID << " has been deleted " << endl;
    else
        cout << "Student " << studentID << " does not exist " << endl;

}
