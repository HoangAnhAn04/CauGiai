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