#include <iostream>
#include <cmath>

int main() {
  long long gt;
  int n;
  std::cout << "Nhap n: ";
  std::cin >> n;
  float x, s = 1;
  std::cout << "Nhap x: ";
  std::cin >> x;
  gt = 1;
  for (int i = 1; i <= n; i++) {
    gt *= i;
    s += (pow(x, i) / gt);
  }
  std::cout << s;
}