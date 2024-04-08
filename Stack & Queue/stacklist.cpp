#include<iostream>
#include<list>
using namespace std;
struct Node{
    int data;
    struct Node* next; 
};
Node *makeNode(int x){
    Node *newNode = new Node();
    newNode->data = x; 
    newNode->next = NULL;
    return newNode;
}

void push(Node **top, int x){
    Node *newNode = makeNode(x);
    newNode->next = (*top);
    *top = newNode; 
}

void pop(Node **top){
    if(*top != NULL){
        Node *temp = *top;
        (*top) = (*top) -> next;
        delete temp;
    }
}

int Top(Node **top){
    if(*top != NULL)
        return (*top)->data; 
}

int size(Node *top){ 
    int dem = 0;
    while(top != NULL){
        dem++;
        top = top->next;
    }
    return dem;
}

void print(Node *top){
    while(top != NULL){
        cout << top->data << " ";
        top = top->next;
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
    Node *nganxep = NULL;
    int chon;
    do{
        menu();
        cout << "Chon: ";
        cin >> chon;
        switch(chon){
            case 1:
                int x;
                cout << "Nhap x: ";
                cin >> x;
                push(&nganxep, x);
                break;
            case 2:
                pop(&nganxep);
                break;
            case 3:
                if (nganxep == 0) cout << "Stack rong \n";
                cout << Top(&nganxep) << endl;
                break;
            case 4:
                cout << size(nganxep) << endl;
                break;
            case 5:
                print(nganxep);
                break;
            default:
                cout << "Nhap sai \n";
                break;
        }   
    }while(chon != 0);
    return 0;
}