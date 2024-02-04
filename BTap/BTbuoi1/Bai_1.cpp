#include<iostream>
int main()
{
    int a, b, c;
    std::cout << "Nhap 3 canh cua tam giac: ";
    std::cin >> a >> b >> c;
    if (a <= 0 || b <= 0 || c <= 0)
        std::cout << "sai cu phap";
    if (a+b>c && a+c>b && b+c>a)
        if ( a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
            std::cout << "Day la tam giac vuong";
        else
            std::cout << "Day khong phai la tam giac vuong";
    else
        std::cout << "Day khong phai la tam giac";
}