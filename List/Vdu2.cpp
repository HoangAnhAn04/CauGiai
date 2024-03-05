#include<iostream>
#include<list>

using namespace std;

class Node{
    public:
        int elem;
        Node *next;
        Node(){
            elem = 99;
            next = NULL;
        }
};

int main(){
    Node A, B, C, D;
    A.elem = 40; A.next = &B;
    B.elem = 50; B.next = &C;
    C.elem = 70; C.next = &D;
    D.elem = 10; 
    Node *p;
    p = &A;
    // for(;p != NULL;){
    //     cout << p->elem << " ";
    //     p = p->next;
    // }
    return 0; 
}