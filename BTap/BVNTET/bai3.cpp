#include <iostream>
#include <cmath>
#include <string>

class Point {
public:
  float x, y;

  void input() {
    std::cout << "Nhap x: ";
    std::cin >> x;
    std::cout << "Nhap y: ";
    std::cin >> y;
  }

  void inputPoint(std::string point) {
    std::cout << point << std::endl;
    input();
  }

  void display() {
    std::cout << "(" << x << ", " << y << ")\n";
  }

  float distance(Point d) {
    float dx = x - d.x;
    float dy = y - d.y;
    return std::sqrt(dx*dx + dy*dy);
  }

  friend std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
};

class Tamgiac {
public:
  Point a, b, c;

  void input() {
    a.inputPoint("Nhap diem A:");
    b.inputPoint("Nhap diem B:");
    c.inputPoint("Nhap diem C:");
  }

  void display() {
    std::cout << "A: " << a << std::endl;
    std::cout << "B: " << b << std::endl;
    std::cout << "C: " << c << std::endl;
  }

  float dientich() {
    float ab = a.distance(b);
    float bc = b.distance(c);
    float ca = c.distance(a);
    float p = (ab + bc + ca) / 2.0;
    return std::sqrt(p * (p - ab) * (p - bc) * (p - ca));
  }

  float chuvi() {
    return a.distance(b) + b.distance(c) + c.distance(a);
  }
};

int main() {
  Tamgiac t;
  t.input();
  t.display();
  std::cout << "Area: " << t.chuvi() << std::endl;
  std::cout << "Perimeter: " << t.dientich() << std::endl;
  return 0;
}