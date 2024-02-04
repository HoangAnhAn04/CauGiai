#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string name;
    int age;
    float averageScore;

public:
    void inputInfo() {
        std::cout << "Enter student's name: ";
        std::cin >> name;
        std::cout << "Enter student's age: ";
        std::cin >> age;
        std::cout << "Enter student's average score: ";
        std::cin >> averageScore;
    }

    void printInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Average Score: " << averageScore << std::endl;
    }

    bool isPass() {
        return averageScore >= 5.0;
    }
};

int main() {
    int n;
    std::cout << "Enter the number of students: ";
    std::cin >> n;

    std::vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        std::cout << "Enter information for student " << i + 1 << std::endl;
        students[i].inputInfo();
    }

    std::cout << "Information of students:" << std::endl;
    for (int i = 0; i < n; i++) {
        students[i].printInfo();
    }

    std::cout << "Students who passed the exam:" << std::endl;
    for (int i = 0; i < n; i++) {
        if (students[i].isPass()) {
            students[i].printInfo();
        }
    }

    return 0;
}