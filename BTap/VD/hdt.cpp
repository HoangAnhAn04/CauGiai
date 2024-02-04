#include <iostream>

class PhanSo{
    public:
        int ts, ms;
        int gcd(int a, int b){
            if (b == 0) return a;
            return gcd(b, a % b);
        }
    public:
        void toigian(){
            int max = gcd(ts,ms);
            ts=ts/max;
            ms=ms/max;
        }
        void InPhanSo(){
            std::cout<<ts<<"/"<<ms<< std::endl;
        }

        void Tich(PhanSo ps, float n){
            ps.ts*=n;
            toigian();
            ps.InPhanSo();
        }

        void Tong(PhanSo ps){
            ps.ts=ts*ps.ms+ps.ts*ms;
            ps.ms=ms*ps.ms;
            ps.toigian();
            ps.InPhanSo();
        }

        void Tong(PhanSo ps1, PhanSo ps2, PhanSo ps3){
            ps3.ts=ps1.ts*ps2.ms+ps2.ts*ps1.ms;
            ps3.ms=ps1.ms*ps2.ms;
            ps3.toigian();
            ps3.InPhanSo();
        }
};

int main()
{
    PhanSo ps, ps2, ps3;
    float n;
    ps.ts=2; ps.ms=3;
    ps2.ts=5; ps2.ms=6;

    ps.toigian();
    ps.InPhanSo();
    std::cout <<"Nhap n: ";  
    std::cin >> n;
    ps.Tich(ps,n);
    ps.Tong(ps);

    ps3.Tong(ps,ps2,ps3);
    return 0;
}
int main(){
    PhanSo a[5];
    a[0].ts=1, a[0].ms=2;
    a[1].ts=2, a[1].ms=3;
    a[2].ts=3, a[2].ms=4;
    a[3].ts=4, a[3].ms=5;
    a[4].ts=5, a[4].ms=9;
    std::cout << "Danh sach phan so: ";
    for(int i=0; i<5; i++){
        a[i].InPhanSo();
    }
    PhanSo tong, tong.ms=1;
    for(int i=0; i<5; i++){
        tong = tong.Tong(a[i]);
    }
}