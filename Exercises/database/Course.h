#include <iostream>
#include <string>

class Course {
public:
    Course(const std::string& name);
    getCourseName() const;
    Course *getNextCourse() const;
    void setNextCourse(Course *course);
private:
    std::string courseName;
    Course* nextCourse;
};