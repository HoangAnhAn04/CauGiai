#include <iostream>

using namespace std;

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

node *makeNode(int x){
	node *newNode = new node();
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void push(node **queue, int x){
	node *newNode = makeNode(x);
	if(*queue == NULL){
		*queue = newNode; return;
	}
	node *temp = *queue;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

void pop(node **queue){
	if(*queue == NULL) return;
	node *temp = *queue;
	(*queue) = (*queue)->next;
	delete temp;
}

int size(node *queue){
	int ans = 0;
	while(queue != NULL){
		++ans;
		queue = queue->next;
	}
	return ans;
}

bool empty(node *queue){
	return queue == NULL;
}

int front(node *queue){
	return queue->data;
}

void print(node *queue){
	while(queue != NULL){
		cout << queue->data << ' ';
		queue = queue->next;
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
	node *queue = NULL;    
    int chon;
    do{
        menu();
        cout << "Nhap lua chon: ";
        cin >> chon;
        switch(chon){
        case 1:
            int x;
            cin >> x;
            push(&queue, x);
            break;
        case 2:
            pop(&queue);
            break;
        case 3:
            cout << front(queue) << endl;
            break;
        case 4:
            cout << size(queue) << endl;
            break;
        case 5:
            if(empty(queue)){
                cout << "EMPTY \n";
            } else {
                cout << "NOT EMPTY \n";
            }
            break;
        case 6:
            print(queue);
            cout << endl;
            break;
        }
    } while (chon != 0);
    return 0;
}

