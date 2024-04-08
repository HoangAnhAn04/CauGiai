#include <iostream>

using namespace std;

class Node {
  public: 
    int elem;
    Node *next;

    Node() {
      elem = 0;
      next = NULL;
    }
};

class List {
  public:
    Node *head, *trail;
    int num;

    List() {
      head = NULL;
      trail = NULL;
      num = 0;
    }

    /* void push_back(int a){
      Node N;
      N.elem = a; N.next = NULL;
      trail -> next = &N;
      trail = &N;
    }
    */

    void push_back(int a) {
      Node *temp = new Node();
      temp->elem = a;
      if (head == NULL) {
        head = temp;
        trail = temp;
      } else {
        trail->next = temp;
        trail = temp;
      }
      num++;
    }
    /* void push_front(int a){
      Node N;
      N.elem = a; N.next = head;
      head = &N;
    }
    */
    void push_front(int a) {
      Node *temp = new Node();
      temp->elem = a;
      if (head == NULL) {
        head = temp;
        trail = temp;
      } else {
        temp->next = head;
        head = temp;
      }
      num++;
    }

    
      //Code của thầy Hưng chuyên máy tính thủ khoa đầu ra 3.68 điểm
    // void insert(int x, int a) {
    //   Node *p = head;
    //   while ( p -> elem != x){
    //     p = p -> next; 
    //   }
    //   if(p == trail) push_back(a);
    //     else{
    //       Node N; 
    //       N.elem = a;
    //       N.next = p -> next;
    //       p -> next = &N;
    //     }
    // }

    void remove(int a) {
      Node *cur = head;
      while (cur != NULL) {
        if (cur->elem == a) {
          Node *temp = head;
          if (cur == head) {
            head = head->next;
            delete temp;
          } else {
            while (temp->next != cur) {
              temp = temp->next;
            }
            temp->next = cur->next;
            delete cur;
          }
          num--;
          return;
        }
        cur = cur->next;
      }
    }
      
    void insert(int x, int a) {
      Node *cur = head;
      while (cur != NULL) {
        if (cur->elem == x) {
          Node *temp = new Node();
          temp->elem = a;
          temp->next = cur->next;
          cur->next = temp;
          num++;
          return;
        }
        cur = cur->next;
      }
    }
 /* void remove(int a){
      Node *p = head;
      while(p->elem != a)
        p = p -> next;
      
      Node *q = head;
      while(q -> next != p)
        q = q -> next;
      q -> next = p -> next;
      delete p;          

 }
 */
};    



int main() {
  List l;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(10000);
  // 1 2 3 4

  l.push_front(-1);
  l.push_front(-2);
  // -2 -1 0 1 2 3 4

  l.insert(3, 0);
  l.insert(1, 7);
  // -2 -1 1 7 2 3 0 4

  l.remove(0);
  l.remove(7);
  // -2 -1 1 2 3 4

  Node *cur = l.head;
  while (cur != NULL) {
    cout << cur->elem << " ";
    cur = cur->next;
  }
  cout << std::endl;


  return 0;
}