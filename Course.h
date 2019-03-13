#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace::std;


class Course
{
    public:
        Course( );
        int getCourseID();
        string getCourseTitle();
        void setCourse( int, string );
        virtual ~Course();


    protected:

    private:
        int id;
        string title;
};

#endif // COURSE_H
