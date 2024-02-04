#include <iostream>
#include <cmath>

class Point {
private:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    void nhapToaDo() {
        std::cout << "Nhap toa do x: ";
        std::cin >> x;
        std::cout << "Nhap toa do y: ";
        std::cin >> y;
    }

    void inToaDo() {
        std::cout << "(" << x << ", " << y << ")";
    }

    double tinhKhoangCach(Point p) {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

class TamGiac {
private:
    Point A;
    Point B;
    Point C;

public:
    void nhapTamGiac() {
        std::cout << "Nhap toa do diem A:\n";
        A.nhapToaDo();
        std::cout << "Nhap toa do diem B:\n";
        B.nhapToaDo();
        std::cout << "Nhap toa do diem C:\n";
        C.nhapToaDo();
    }

    void inTamGiac() {
        std::cout << "Toa do diem A: ";
        A.inToaDo();
        std::cout << "\nToa do diem B: ";
        B.inToaDo();
        std::cout << "\nToa do diem C: ";
        C.inToaDo();
        std::cout << std::endl;
    }

    double tinhChuVi() {
        double AB = A.tinhKhoangCach(B);
        double BC = B.tinhKhoangCach(C);
        double CA = C.tinhKhoangCach(A);
        return AB + BC + CA;
    }

    double tinhDienTich() {
        double AB = A.tinhKhoangCach(B);
        double BC = B.tinhKhoangCach(C);
        double CA = C.tinhKhoangCach(A);
        double p = (AB + BC + CA) / 2;
        return sqrt(p * (p - AB) * (p - BC) * (p - CA));
    }
};

int main() {
    TamGiac tamGiac;
    tamGiac.nhapTamGiac();
    std::cout << "Tam giac vua nhap:\n";
    tamGiac.inTamGiac();
    std::cout << "Chu vi: " << tamGiac.tinhChuVi() << std::endl;
    std::cout << "Dien tich: " << tamGiac.tinhDienTich() << std::endl;

    return 0;
}