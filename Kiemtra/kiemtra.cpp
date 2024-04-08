#include<iostream>
#include<string>
#include<vector>

using namespace std;

template <class T>
class SList{
    public:
        struct Node{
            T elem;
            Node *next;
        };
    
        Node *head, *tail;

        SList(){
            head = tail = NULL;
        }

        void printList(){
            for (Node *p = head; p != NULL; p = p->next){ 
                cout << p->elem << endl; 
            }
        }

        void push_back(T x){
            Node *node = new Node; 
            node->elem = x; 
            node->next = NULL; 
            if (head == NULL){ 
                head = tail = node; 
            } else { 
                tail -> next = node;
                tail = node ; 
            }
        }

        void push_front(T x){
            Node *node= new Node; 
            node -> elem = x; 
            node -> next = head; 
            head = node; 
            if (tail == NULL){ 
                tail = head; 
            }
        }

        void erase(T x){
            Node *p = head;
            Node *prev = NULL;
            while (p != NULL && p->elem !=x){ 
                prev = p; 
                p = p->next; 
            }
            if (p != NULL){ 
                if (prev == NULL){ 
                    head = p -> next; 
                } else {   
                    prev -> next = p -> next; 
                }
                delete p; 
            }
        }

        void search(){
            
        }
};
class DocGia{
    public:

        int madocgia;
        string tendocgia, namsinh, diachi;

        DocGia(){
            madocgia = 0;
            tendocgia = "";
            namsinh = "";
            diachi = "";
        }

        DocGia(string tendocgia, string namsinh, string diachi, int madocgia):
        madocgia(madocgia), tendocgia(tendocgia), namsinh(namsinh), diachi(diachi) {}

        friend ostream& operator<<(ostream &os, const DocGia &dg){
            return os <<"----------Thong tin doc gia----------\n"
                      <<"Ma doc gia: "<< dg.madocgia
                      <<"\nTen doc gia: "<< dg.tendocgia
                      <<"\nNam sinh: " << dg.namsinh
                      <<"\nDia chi: " << dg.diachi;            
        }

        bool operator!=(const DocGia& other) const {  
        return madocgia != other.madocgia;
    }

        DocGia themDocGia(){
            DocGia dg;
            cout << "----------Nhap thong tin doc gia----------" << endl;
            cout << "Nhap ma doc gia: "; 
            cin >> dg.madocgia;
            cout << "Nhap ten doc gia: ";
            cin.ignore();
            getline(cin, dg.tendocgia);
            cout << "Nhap nam sinh: ";
            getline(cin, dg.namsinh);
            cout << "Nhap dia chi: ";
            getline(cin, dg.diachi);
            cout << "----------------------";
            return dg;
        }
};

void menu(){
            cout << "----------Menu----------" << endl;
            cout << "1. Them mot doc gia" << endl;
            cout << "2. In danh sach doc gia " << endl;
            cout << "3. Xoa mot doc gia theo ma" << endl;
            cout << "4. Tim kiem doc gia theo ten" << endl;
            cout << "0. Thoat" << endl;
            cout << "------------------------" << endl;
            cout << "Nhap lua chon: ";
        }

int main(){
    SList<DocGia> lishdocgia;

    DocGia dg;
    int chon;

    do{
        menu();
        cin >> chon;
        switch(chon){
        case 1:
            lishdocgia.push_back(dg.themDocGia());
            break;
        case 2:
            lishdocgia.printList();
            break;   
        case 3:
            int madocgia;
            cout << "Nhap ma doc gia can xoa: ";
            cin >> madocgia;
            lishdocgia.erase(DocGia("", "", "", madocgia)); 
            break;
        default:
            cout << "Lua chon khong hop le. Moi nhap lai." << endl;
        }
    }
    while(chon != 0);
    return 0;
}


