#include <iostream>
#include <chrono>
#include <thread>

void countdown(int seconds) {
    for (int i = seconds; i >= 0; --i) {
        std::cout << "Countdown: " << i << " seconds remaining" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    countdown(n);

    std::cout << "Time's up!" << std::endl;

    return 0;
}
