#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0)); // Khởi tạo bộ sinh số ngẫu nhiên
    int luckyNumber = rand() % 100; // Tạo số ngẫu nhiên từ 0 đến 99

    std::vector<int> guesses; // Vector để lưu số lần đoán
    int userGuess;

    std::cout << "Welcome to Lucky Number game! Guess a number between 0 and 99.\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        guesses.push_back(userGuess); // Thêm số đoán vào vector

        if (userGuess > luckyNumber) {
            std::cout << "Your guess is too high!\n";
        } else if (userGuess < luckyNumber) {
            std::cout << "Your guess is too low!\n";
        }
    } while (userGuess != luckyNumber);

    std::cout << "Congratulations! You've guessed the lucky number.\n";
    std::cout << "You've made " << guesses.size() << " guesses.\n";

    return 0;p
}