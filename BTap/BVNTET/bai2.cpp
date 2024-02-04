#include <iostream>
#include <cmath>
#include <string>

class Diem {
private:
    double x;
    double y;

public:
    // Phương thức khởi tạo
    Diem(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }

    // Phương thức nhập điểm
    void nhap() {
        std::cout << "Nhap toa do x: ";
        std::cin >> x;
        std::cout << "Nhap toa do y: ";
        std::cin >> y;
    }
    void inputpoint(std::string diem ) {
        std::cout<< "diem " << diem << std::endl;
        nhap();
    }
    // Phương thức in điểm
    void in() {
        std::cout << "Toa do diem: (" << x << ", " << y << ")" << std::endl;
    }

    // Phương thức tính khoảng cách từ điểm hiện tại tới điểm khác
    double tinhKhoangCach(Diem diemKhac) {
        double deltaX = x - diemKhac.x;
        double deltaY = y - diemKhac.y;
        return std::sqrt(deltaX * deltaX + deltaY * deltaY);
    }
};

int main() {
    Diem diem1;
    diem1.inputpoint("1");
    diem1.in();

    Diem diem2;
    diem2.inputpoint("2");
    diem2.in();


    double khoangCach = diem1.tinhKhoangCach(diem2);
    std::cout << "Khoang cach giua hai diem: " << khoangCach << std::endl;

    return 0;
}