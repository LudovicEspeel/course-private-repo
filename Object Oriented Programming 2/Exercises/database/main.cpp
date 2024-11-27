#include <iostream>
#include <vector>
#include <string>



class Student {
public:
    Student(const std::string& name) : studentName(name), courses(nullptr), nextStudent(nullptr) {}

    std::string getStudentName() const {
        return studentName;

        PersonsDatabase personsDatabase;
    }

    void addCourse(const std::string& courseName) {
        Course* newCourse = new Course(courseName);
        newCourse->setNextCourse(courses);
        courses = newCourse;
    }

    void displayCourses() const {
        Course* currentCourse = courses;
        while (currentCourse != nullptr) {
            std::cout << " - " << currentCourse->getCourseName() << std::endl;
            currentCourse = currentCourse->getNextCourse();
        }
    }

    Student* getNextStudent() const {
        return nextStudent;
    }

    void setNextStudent(Student* student) {
        nextStudent = student;
    }

private:
    std::string studentName;
    Course* courses;
    Student* nextStudent;
};

class StudentDatabase {
public:
    StudentDatabase(int size) : hashTable(size, nullptr) {}

    void addStudent(const std::string& studentName) {
        int index = hashFunction(studentName);
        Student* newStudent = new Student(studentName);
        newStudent->setNextStudent(hashTable[index]);
        hashTable[index] = newStudent;
    }

    void displayStudents() const {
        for (const auto& studentList : hashTable) {
            Student* currentStudent = studentList;
            while (currentStudent != nullptr) {
                std::cout << "Student: " << currentStudent->getStudentName() << std::endl;
                std::cout << "Courses:" << std::endl;
                currentStudent->displayCourses();
                std::cout << std::endl;
                currentStudent = currentStudent->getNextStudent();
            }
        }
    }

    Student* searchStudent(const std::string& studentName) const {
        int index = hashFunction(studentName);
        Student* currentStudent = hashTable[index];
        while (currentStudent != nullptr) {
            if (currentStudent->getStudentName() == studentName) {
                return currentStudent;
            }
            currentStudent = currentStudent->getNextStudent();
        }
        return nullptr; // Student niet gevonden
    }

private:
    std::vector<Student*> hashTable;
    
    // Eenvoudige hashfunctie om index te berekenen op basis van de naam van de student
    int hashFunction(const std::string& studentName) const {
        return studentName.length() % hashTable.size();
    }
};

int main() {
    StudentDatabase studentDatabase(10);

    studentDatabase.addStudent("John Doe");
    studentDatabase.addStudent("Jane Smith");

    // Voeg cursussen toe aan de eerste student
    Student* firstStudent = studentDatabase.searchStudent("John Doe");
    if (firstStudent != nullptr) {
        firstStudent->addCourse("Programming 101");
        firstStudent->addCourse("Database Management");
    }

    // Voeg cursussen toe aan de tweede student
    Student* secondStudent = studentDatabase.searchStudent("Jane Smith");
    if (secondStudent != nullptr) {
        secondStudent->addCourse("Data Structures");
        secondStudent->addCourse("Algorithms");
    }

    // Toon de informatie van alle studenten
    studentDatabase.displayStudents();

    for(int i = 0; i < 1000; i++)
    {
        
    }

    return 0;
}
