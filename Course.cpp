#include "Course.h"
#include <string>
using namespace::std;

Course::Course(  )
{
}

Course::~Course()
{
    //dtor
}

int Course :: getCourseID()
{
    return id;
}

string Course :: getCourseTitle()
{
    return title;
}

void Course :: setCourse( int courseID, string courseTitle )
{
    id = courseID;
    title = courseTitle;
}
