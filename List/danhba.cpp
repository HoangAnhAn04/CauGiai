#include <iostream>
#include <string>


class DanhBa {
  private:
    struct Node {
      std::string soThueBao;
      std::string hoTen;
      std::string diaChi;
      Node* next;
    };
    Node* head;

    Node* taoNut(std::string soThueBao, std::string hoTen, std::string diaChi) {
      Node* node = new Node;
      node->soThueBao = soThueBao;
      node->hoTen = hoTen;
      node->diaChi = diaChi;
      return node;
    }

    Node* timNut(std::string soThueBao) {
      Node* node = head;
      while (node != nullptr && node->soThueBao != soThueBao) {
        node = node->next;
      }
      return node;
    }

  public:
    DanhBa() {
      head = nullptr;
    };

    ~DanhBa() {
      while (head != nullptr) {
        Node* node = head;
        head = head->next;
        delete node;
      }
    };

    void inDanhSach() {
      Node* node = head;
      while (node != nullptr) {
        std::cout << "----------------" << std::endl;
        std::cout << "So thue bao: " << node->soThueBao << std::endl;
        std::cout << "Ho ten: " << node->hoTen << std::endl;
        std::cout << "Dia chi: " << node->diaChi << std::endl;
        std::cout << "----------------" << std::endl;
        node = node->next;
      }
    }

    void themDau(std::string soThueBao, std::string hoTen, std::string diaChi) {
      Node* node = taoNut(soThueBao, hoTen, diaChi);
      node->next = head;
      head = node;
    }

    void themCuoi(std::string soThueBao, std::string hoTen, std::string diaChi) {
      Node* node = taoNut(soThueBao, hoTen, diaChi);
      node->next = nullptr;
      if (head == nullptr) {
        head = node;
      } else {
        Node* newNode = head;
        while (newNode->next != nullptr) {
          newNode = newNode->next;
        }
        newNode->next = node;
      }
    }

    void xoa(std::string soThueBao) {
      Node* node = timNut(soThueBao);
      if (node != nullptr) {
        if (node == head) {
          head = head->next;
        } else {
          Node* prev = head;
          while (prev->next != node) {
            prev = prev->next;
          }
          prev->next = node->next;
        }
        delete node;
      }
      inDanhSach();
    }
    
    void timKiem(std::string soThueBao) {
      Node* node = timNut(soThueBao);
      if (node != nullptr) {
        std::cout << "So thue bao: " << node->soThueBao << std::endl;
        std::cout << "Ho ten: " << node->hoTen << std::endl;
        std::cout << "Dia chi: " << node->diaChi << std::endl;
      } else {
        std::cout << "Khong tim thay so thue bao " << soThueBao << std::endl;
      }
    }
};
 
using namespace std;

struct ThongTin {
  string soThueBao;
  string hoTen;
  string diaChi;
};

void nhapThongTin(ThongTin& thongTin) {
  cout << "Nhap so thue bao: ";
  cin >> thongTin.soThueBao;
  cin.ignore();
  cout << "Nhap ho ten: ";
  getline(cin, thongTin.hoTen);
  cout << "Nhap dia chi: ";
  getline(cin, thongTin.diaChi);
}

int main() {
  DanhBa danhBa;
  ThongTin thongtin;
  int choice;

  danhBa.themDau("123", "Nguyen Van A", "123 ABC");

  do {
    cout << "----------------" << endl;
    cout << "0. Thoat" << endl;
    cout << "1. In danh sach" << endl;
    cout << "2. Them vao dau" << endl;
    cout << "3. Them vao cuoi" << endl;
    cout << "4. Xoa" << endl;
    cout << "5. Tim kiem" << endl;
    cout << "----------------" << endl;

    cout << "Nhap lua chon: ";
    cin >> choice;
    switch (choice) {
      case 1:
        danhBa.inDanhSach();
        break;
      case 2:
        nhapThongTin(thongtin);
        danhBa.themDau(thongtin.soThueBao, thongtin.hoTen, thongtin.diaChi);
        break;
      case 3:
        nhapThongTin(thongtin);
        danhBa.themCuoi(thongtin.soThueBao, thongtin.hoTen, thongtin.diaChi);
        break;
      case 4:
        cout << "Nhap so thue bao can xoa: ";
        cin >> thongtin.soThueBao;
        danhBa.xoa(thongtin.soThueBao);
        break;
      case 5: 
        cout << "Nhap so thue bao can tim: ";
        cin >> thongtin.soThueBao;
        danhBa.timKiem(thongtin.soThueBao);
        break;
      default:
        break;
    }
  } while (choice != 0);
  
  
  return 0;
}