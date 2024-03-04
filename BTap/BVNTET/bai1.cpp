#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

class Time {
  private:
    int hour;
    int minute;
    int second;

  public:
    void normalizeTime() {
      if (second < 0) {
          second += 60;
          minute--;
      }
      if (minute < 0) {
          minute += 60;
          hour--;
      }
      minute += second / 60;
      second %= 60;
      hour += minute / 60;
      minute %= 60;
      hour %= 24;
    }

    void inputTime() {
      std::cout << "Enter hour: ";
      std::cin >> hour;
      std::cout << "Enter minute: ";
      std::cin >> minute;
      std::cout << "Enter second: ";
      std::cin >> second;
      normalizeTime();
    }

    void displayTime() {
      std::cout 
            << std::setfill('0') << std::setw(2) << hour << ":"
            << std::setfill('0') << std::setw(2) << minute << ":"
            << std::setfill('0') << std::setw(2) << second << "\n";
    }

    bool isZero() {
      return hour == 0 && minute == 0 && second == 0;
    }


    void countDown() {
      while (!isZero()) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        second--;
        normalizeTime();
        system("cls");
        displayTime();
      }
    }
};
int main() {
  Time t;
  t.inputTime();
  t.displayTime();
  t.countDown();
  return 0;
}
