#include<iostream>
#include<stack>

using namespace std;

// void nhiPhan(stack<int> s, int n){
//     while(n>0){
//         s.push(n%2);
//         n/=2;
//     }
//     while(!s.empty()){
//         cout<<s.top();
//         s.pop();
//     }
    
// }
// int main(){
//     stack<int> s;
//     int n;
//     cout<<"Nhap so n: ";
//     cin>>n;
//     nhiPhan(s,n);
//     return 0;
// }
int main(){
    stack<int> s;
    int n;
    cout << "Nhap so can chuyen: ";
    cin >> n;
    while(n != 0){
        s.push(n % 2);
        n /= 2;
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    return 0;
}