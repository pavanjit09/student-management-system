#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    int rollNumber;
    std::string name;
    std::vector<double> grades;

public:
    Student(int roll, const std::string& n) : rollNumber(roll), name(n) {}

    void addGrade(double grade) {
        grades.push_back(grade);
    }

    void displayDetails() const {
        std::cout << "Roll Number: " << rollNumber << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Grades: ";
        for (double grade : grades) {
            std::cout << grade << " ";
        }
        std::cout << std::endl;
    }

    int getRollNumber() const {
        return rollNumber;
    }
};

class StudentManagement {
private:
    std::vector<Student> students;

public:
    void addStudent(int roll, const std::string& name) {
        students.emplace_back(roll, name);
    }

    void addGradeToStudent(int roll, double grade) {
        for (auto& student : students) {
            if (student.getRollNumber() == roll) {
                student.addGrade(grade);
                return;
            }
        }
        std::cout << "Student not found!" << std::endl;
    }

    void displayStudentDetails(int roll) const {
        for (const auto& student : students) {
            if (student.getRollNumber() == roll) {
                student.displayDetails();
                return;
            }
        }
        std::cout << "Student not found!" << std::endl;
    }
};

int main() {
    StudentManagement sm;
    sm.addStudent(1, "Alice");
    sm.addStudent(2, "Bob");

    sm.addGradeToStudent(1, 90.5);
    sm.addGradeToStudent(1, 85.0);
    sm.addGradeToStudent(2, 78.0);

    sm.displayStudentDetails(1);
    sm.displayStudentDetails(2);

    return 0;
}

