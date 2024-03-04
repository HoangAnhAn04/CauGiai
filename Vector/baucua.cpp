#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0)); // Khởi tạo bộ sinh số ngẫu nhiên

    std::string animals[6] = {"Bau", "Cua", "Tom", "Ca", "Ga", "Bao cow"};
    int userChoice, randomChoice;

    std::cout << "Welcome to Bau Cua game! Choose an animal:\n";
    for (int i = 0; i < 6; i++) {
        std::cout << i + 1 << ". " << animals[i] << "\n";
    }

    std::cout << "Enter your choice (1-6): ";
    std::cin >> userChoice;
    userChoice--; // Điều chỉnh để phù hợp với chỉ mục của mảng

    if (userChoice < 0 || userChoice > 5) {
        std::cout << "Invalid choice. Exiting game.\n";
        return 0;
    }

    randomChoice = rand() % 6; // Tạo một lựa chọn ngẫu nhiên từ 0 đến 5

    std::cout << "You chose: " << animals[userChoice] << "\n";
    std::cout << "The result is: " << animals[randomChoice] << "\n";

    if (userChoice == randomChoice) {
        std::cout << "Congratulations! You win.\n";
    } else {
        std::cout << "Sorry, you lose. Better luck next time!\n";
    }

    return 0;
}