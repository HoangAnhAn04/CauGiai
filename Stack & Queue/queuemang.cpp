#include <iostream>

using namespace std;

int a[100000], maxN = 100000;
int n = 0;

int size(){
	return n;
}

bool empty(){
	return n == 0;
}


void push(int x){
	if(n == maxN) return;
	a[n] = x; ++n;
}

void pop(){
	if(n == 0) return;
	for(int i = 0; i < n - 1; i++){
		a[i] = a[i + 1];
	}
	--n;
}

int front(){
	return a[0];
}

void print(){
    for(int i = 0; i <= n - 1; i++){
        cout << a[i] << " ";
    }
}

void menu(){
    cout << "------------------------------ \n";
    cout << "1. Push \n";
    cout << "2. Pop \n";
    cout << "3. Front \n";
    cout << "4. Size \n";
    cout << "5. Is Empty \n";
    cout << "6. Print \n";
    cout << "0. Exit \n";
    cout << "------------------------------ \n";
}

int main(){
	 int chon;
    do{
        menu();
        cout << "Nhap lua chon: ";
        cin >> chon;
        switch(chon){
            case 1:
                int x;
                cin >> x;
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << front() << endl;
                break;
            case 4:
                cout << size() << endl;
                break;
            case 5:
                if(empty()){
                    cout << "Empty \n";
                } else {
                    cout << "Not Empty \n";
                }
                break;
            case 6:
                print();
                break;
            case 0:
                cout << "Exit \n";
                break;
            default:
                cout << "Nhap sai \n";
        }     
    }
    while(chon != 0); 
    return 0;
}

