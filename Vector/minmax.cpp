#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cout << "Nhap so phan tu cua day so: ";
    cin >> n;
    vector<int> numbers;
    
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    int max = numbers[0];
    int min = numbers[0];
    for(int i=0; i<n; i++){
        if(numbers[i] > max){
            max = numbers[i];
        }
        if(numbers[i] < min){
            min = numbers[i];
        }
    }
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    return 0;
}