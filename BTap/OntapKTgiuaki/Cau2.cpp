#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tivi{
    public: 
        vector <Tivi> listTV;

        string maHang,hangSX,tenTV;
        int donGia, soLuong;

        Tivi(){
            maHang = "";
            hangSX = "";
            tenTV = "";
            donGia = 0;
            soLuong = 0;
        } 
        
        Tivi( string maHang,  string hangSX,  string tenTivi, int donGia, int soLuong):
        maHang(maHang), hangSX(hangSX), tenTV(tenTivi), donGia(donGia), soLuong(soLuong) {}

        void themTivi(){
            Tivi tivi;
            cout << "----------Nhap thong tin TV----------" << endl;
            cout << "Nhap ma hang: "; cin >> tivi.maHang;
            cout << "Nhap hang SX: "; cin >> tivi.hangSX;
            cin.ignore();
            cout << "Nhap ten tivi: ";
            getline(cin, tivi.tenTV);
            cout << "Nhap don gia: ";
            cin >> tivi.donGia;
            cout << "Nhap so luong: ";
            cin >> tivi.soLuong;
            listTV.push_back(tivi);
        }

        void xuat(){
            cout << "----------Danh sach TV----------" << endl;
            for (auto &tivi : listTV){
                cout << "------------------------" << endl;
                cout << "Ma hang: " << tivi.maHang << endl;
                cout << "Hang SX: " << tivi.hangSX << endl;
                cout << "Ten tivi: " << tivi.tenTV << endl;
                cout << "Don gia: " << tivi.donGia << endl;
                cout << "So luong: " << tivi.soLuong << endl;
                cout << "------------------------" << endl;
            }
        }
        
        void xoa(){
            string maHang;
            cout << "Nhap ma hang can xoa: " ;
            cin >> maHang;
            for (auto iterator = listTV.begin(); iterator != listTV.end(); iterator ++){
                if(maHang == iterator->maHang){
                    listTV.erase(iterator);
                    break;
                }
            }
            xuat();
        }

        long long tong( string &hangSX){
            int tonggia = 0;
            for (auto &tivi : listTV){
                if(tivi.hangSX == hangSX && tivi.soLuong > 0){
                    tonggia += tivi.soLuong * tivi.donGia;
                } 
            } 
            return tonggia;
        }
};

void menu(){
            cout << "----------Menu----------" << endl;
            cout << "1. Them mot Tivi" << endl;
            cout << "2. Xoa mot Tivi theo ma" << endl;
            cout << "3. Tong hang hoa ton kho theo mot hang san xuat" << endl;
            cout << "4. In danh sach Tivi" << endl;
            cout << "0. Thoat" << endl;
            cout << "------------------------" << endl;
            cout << "Nhap lua chon: ";
        }

int main(){
    Tivi tv;
    int chon;
    string hangSX ;
    
    Tivi a("SS01", "SamSung", "Samsung 50 Inch", 7900000, 3);
    Tivi b("LG01", "LG", "LG 55 Inch", 7500000, 2);  
    Tivi c("XA01", "Xiaomi", "Xiaomi 55 Inch", 5900000, 5);
    tv.listTV.push_back(a);
    tv.listTV.push_back(b);
    tv.listTV.push_back(c);

    do{
        menu();
        cin >> chon;
        switch(chon){
        case 1:
            tv.themTivi();
            break;
        case 2:
            tv.xoa();
            break;
        case 3:
            cout << "Hang san xuat: "; cin >> hangSX;
            cout << "Tong gia tri hang hoa ton kho: " << tv.tong(hangSX) << endl;
            break;
        case 4:
            tv.xuat();
            break;
        default:
            cout << "Lua chon khong hop le. Moi nhap lai." << endl;
        }
    }
    while(chon != 0);
    return 0;
}

