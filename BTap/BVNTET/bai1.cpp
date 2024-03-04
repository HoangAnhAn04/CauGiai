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
    normalizeTime();
  }

  void displayTime() {
    cout 
      << setfill('0') << setw(2) << hour << ":"
      << setfill('0') << setw(2) << minute << ":"
      << setfill('0') << setw(2) << second << "\n";
  }

private:
  void normalizeTime() {
    minute += second / 60;
    second %= 60;
    hour += minute / 60;
    minute %= 60;
    hour %= 24;
    }
};

int main() {
  Time t;
  t.inputTime();
  t.displayTime();
  return 0;
}
