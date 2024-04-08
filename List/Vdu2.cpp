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
    Node *head=&A;
    Node *trail = &D;
    Node *p;
    Node q;
    q.elem=99;
    q.next=&A;
    head = &q;

    Node bob;
    bob.elem = 17;
    trail -> next=&bob;
    trail = trail -> next;// Mấu chốt

    Node Bull; 
    Bull.elem = 00;
    trail -> next = &Bull;

    Node cow;
    cow.elem = 1;
    cow.next =&B; A.next = &cow;

    for(p = head ;p != NULL;){
        cout << p->elem << " ";
        p = p->next;
    }
    return 0; 
}