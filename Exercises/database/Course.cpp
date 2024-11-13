class Course {
public:
    Course(const std::string& name) : courseName(name), nextCourse(nullptr) {}

    std::string getCourseName() const {
        return courseName;
    }

    Course* getNextCourse() const {
        return nextCourse;
    }

    void setNextCourse(Course* course) {
        nextCourse = course;
    }

private:
    std::string courseName;
    Course* nextCourse;
};