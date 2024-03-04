// lucky number 0-99
#include <iostream>
#include <vector>
#include <random>

using namespace std;   

int main(){
    int a;
    srand(time(NULL));
    a=rand()%100;
    cout << "Lucky number: " << a << endl;
}