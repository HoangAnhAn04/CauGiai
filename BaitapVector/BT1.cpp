#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    int n, tong = 0, x;
    cout << "Nhap so phan tu cua vector: ";
    cin >> n;
    int i; 
    for (i = 0; i < n; i++){ 
        cin >> x;
        v.push_back(x); 
        tong += v[i];
    }
    cout<< "Tong cac phan tu: " << tong;
    return 0;
}