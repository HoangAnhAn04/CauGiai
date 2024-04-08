#include<iostream>
#include<vector>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void increase(vector<int>& v, int n){
    for(int i = 0; i < n-1; i++){
        int tg= i;
        for(int j = i+1; j < n; j++){
            if(v[j] < v[tg]){
                tg = j;
            }
        }
        if(tg != i){
            swap(v[i], v[tg]);
        }
    }
}

void decrease(vector<int>& v, int n){
    for(int i = 0; i < n-1; i++){
        int td=i;
        for(int j = i+1; j < n; j++){
            if(v[j] > v[td]){
                td = j;
            }
        }
        if(td != i){
            swap(v[i], v[td]);
        }
    }
}

int main(){
    int n, x, chon;
    vector<int> v;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
   
    cout << "Chon phuong thuc:(1 - tang dan) (2 - giam dan) " << endl;
    cin >> chon;
    switch(chon){
        case 1:
            increase(v, n);
            break;
        case 2:
            decrease(v, n);
            break;
    }
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    return 0;
}

