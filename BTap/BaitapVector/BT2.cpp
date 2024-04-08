#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    int x, n, dem = 0, a;
    cout << "Nhap so phan tu cua vector: ";
    cin >> n;
    cout << "Phan tu can dem: ";
    cin >> a;
    for(int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);
        if( a == v[i] )
            dem ++;
    }
    cout<< "Dem: " << dem;
    return 0;
}
