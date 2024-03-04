#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student {
private:
    string name;
    int age;
    float averageScore;

public:
    void inputInfo() {
        cout << "Enter student's name: "; 
        cin.ignore();
        getline(cin,name);
        cout << "Enter student's age: ";
        cin >> age;
        cout << "Enter student's average score: ";
        cin >> averageScore;
    }

    void printInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Average Score: " << averageScore << endl;
    }

    bool isPass() {
        return averageScore >= 5.0;
    }
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter information for student " << i + 1 << endl;
        students[i].inputInfo();
    }

    cout << "Information of students:" << endl;
    for (int i = 0; i < n; i++) {
        students[i].printInfo();
    }

    cout << "Students who passed the exam:" << endl;
    for (int i = 0; i < n; i++) {
        if (students[i].isPass()) {
            students[i].printInfo();
        }
    }

    return 0;
}