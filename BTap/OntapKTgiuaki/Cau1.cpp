// Danh sách liên kết đơn - Singly linked list là một cấu trúc dữ liệu, nó tương tự như một mảng động 
// với những tính chất quan trọng như sau : 
    // Mở rộng và thu hẹp một cách linh hoạt
    // Các phần tử trong DSLK gọi là node và được cấp phát động khi cần
    // Số lượng phần tử trong DSLK phụ thuộc vào bộ nhớ heap
    // Dễ dàng chèn và xóa phần tử
    // Các phần tử trong DSLK không có thứ tự 
    // Truy cập phần tử trong DSLK cần truy cập tuần tự không thể truy cập qua chỉ số
    // Mỗi node trong DSLK cần có thêm 1 con trỏ để lưu liên kết
#include<iostream>

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
};

template <class P>
class Point { 
  private:
    P x;
    P y;
  public:
    Point(P x = 0, P y = 0) : x(x), y(y) {}
    friend ostream& operator << (ostream& os, const Point& point) {
      return os << "(" << point.x << ", " << point.y << ")"; 
    }
    bool operator!=(const Point& other) const {  //const hàm hằng không thay đổi giá trị của biến trong quá trình thực thi
      return x != other.x || y != other.y;
    }
};

int main(){
    SList<Point<double>> diem;
    Point p1(3.4, 1.2);
    Point p2(-12.0, 2.0);
    Point p3(3.4, 2.0);

    diem.push_front(p1);
    diem.push_front(p2);
    diem.push_front(p3);
    
    diem.printList();
    diem.erase(p2);
    diem.printList();
    return 0;
}
