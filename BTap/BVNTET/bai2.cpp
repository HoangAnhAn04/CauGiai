#include <iostream>
#include <cmath>
#include <string>
using namespace std;
class Point {
private:
    double x;
    double y;

public:
    // Phương thức khởi tạo
    Point(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }

    // Phương thức nhập điểm
    void nhap() {
        cout << "Nhap toa do x: ";
        cin >> x;
        cout << "Nhap toa do y: ";
        cin >> y;
    }
    void inputpoint(string diem ) {
        cout<< "diem " << diem << endl;
        nhap();
    }
    // Phương thức in điểm
    void in() {
        cout << "Toa do diem: (" << x << ", " << y << ")" << endl;
    }

    // Phương thức tính khoảng cách từ điểm hiện tại tới điểm khác
    double tinhKhoangCach(Point diemKhac) {
        double deltaX = x - diemKhac.x;
        double deltaY = y - diemKhac.y;
        return sqrt(deltaX * deltaX + deltaY * deltaY);
    }
};

int main() {
    Point diem1;
    diem1.inputpoint("1");
    diem1.in();

    Point diem2;
    diem2.inputpoint("2");
    diem2.in();

    double khoangCach = diem1.tinhKhoangCach(diem2);
    cout << "Khoang cach giua hai diem: " << khoangCach << endl;

    return 0;
}