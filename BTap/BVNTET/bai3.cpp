#include <iostream>
#include <cmath>
#include <string>
using namespace std;
class Point {
public:
  float x, y;

  void input() {
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
  }

  void inputPoint(string point) {
    cout << point << endl;
    input();
  }

  void display() {
    cout << "(" << x << ", " << y << ")\n";
  }

  float distance(Point d) {
    float dx = x - d.x;
    float dy = y - d.y;
    return sqrt(dx*dx + dy*dy);
  }

  friend ostream& operator<<(ostream& os, const Point& p) {
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
    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
    cout << "C: " << c << endl;
  }

  float dientich() {
    float ab = a.distance(b);
    float bc = b.distance(c);
    float ca = c.distance(a);
    float p = (ab + bc + ca) / 2.0;
    return sqrt(p * (p - ab) * (p - bc) * (p - ca));
  }

  float chuvi() {
    return a.distance(b) + b.distance(c) + c.distance(a);
  }
};

int main() {
  Tamgiac t;
  t.input();
  t.display();
  cout << "Area: " << t.chuvi() << endl;
  cout << "Perimeter: " << t.dientich() << endl;
  return 0;
}