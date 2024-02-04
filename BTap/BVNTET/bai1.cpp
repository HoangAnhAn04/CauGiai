#include <iostream>
#include <iomanip>

using namespace std;

class Time {

private:
    int hour;
    int minute;
    int second;

public:
    
    void inputTime() {
        cout << "Enter hour: ";
        cin >> hour;
        cout << "Enter minute: ";
        cin >> minute;
        cout << "Enter second: ";
        cin >> second;
    }

    void printTime() {
        cout << setfill('0') << setw(2) << hour << ":"
             << setfill('0') << setw(2) << minute << ":"
             << setfill('0') << setw(2) << second << "\n";
    }
};

int main() {
    Time t;
    t.inputTime();
    t.printTime();
    return 0;
}