#include<iostream>
#include<list>

using namespace std;

int main(){
    int Tong = 0;
    list<int> mylist (2,100);
    mylist.push_front(200);
    mylist.push_front(300);
    cout << "Tong: ";
    for (list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it){
        cout << ' ' << *it;
        Tong += *it;
    }
    cout << " = " << Tong;
    cout << '\n';
    return 0;
}