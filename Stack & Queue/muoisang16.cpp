#include<iostream>
#include<stack>

using namespace std;

void hexadecimal(stack<int> s, int n){
    while(n != 0){
        s.push(n % 16);
        n /= 16;  
    }
    while(!s.empty()){
        int x = s.top();
        if(x < 10){
            cout << x;
        }else{
            cout << (char)(x + 55);
        }
        s.pop();
    }
}

int main(){
    stack<int> s;
    int n;
    cout << "Nhap so can chuyen: ";
    cin >> n;
    hexadecimal(s, n);
    return 0;
}

