#include<iostream>

using namespace std;

int dem = 0, stack[1001];

void push(int x){
    stack[dem] = x; 
    dem++;
}

void pop(){
    if (dem > 0) dem--;
}

int getTop(){
    return stack[dem-1];
}

int size(){
    return dem;
}
void print(){
    for (int i = dem - 1; i >=0  ; i--){
        cout << stack[i] << " ";
    }
    cout << endl;
}

void menu(){
    cout << "------------------------------ \n";
    cout << "1. push \n";
    cout << "2. pop \n";
    cout << "3. getTop \n";
    cout << "4. size \n";
    cout << "5. print \n";
    cout << "0. exit \n";
    cout << "------------------------------ \n";
}

int main(){
    int chon;
    
    do{
        menu();
        cin >> chon;
        switch(chon){
            case 1:
                int x;
                cout << "Nhap x: ";
                cin >> x;
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << getTop() << endl;
                break;
            case 4:
                cout << size() << endl;
                break;
            case 5:
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