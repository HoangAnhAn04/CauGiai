#include<iostream>
#include<stack>
#include<map>

using namespace std;

int chemical(stack<int> s, string x){
    map<string, int> K={
    {"H", 1}, {"He", 4}, {"Li", 7}, {"Be", 9}, {"B", 11}, {"C", 12}, {"N", 14}, {"O", 16}, {"F", 19}, {"Ne", 20}, 
    {"Na", 23}, {"Mg", 24}, {"Al", 27}, {"Si", 28}, {"P", 31}, {"S", 32}, {"Cl", 35}, {"Ar", 40}, {"K", 39}, {"Ca", 40},
    {"Sc", 45}, {"Ti", 48}, {"V", 51}, {"Cr", 52}, {"Mn", 55}, {"Fe", 56}, {"Co", 59}, {"Ni", 59}, {"Cu", 64}, {"Zn", 65},
    {"Ga", 70}, {"Ge", 73}, {"As", 75}, {"Se", 79}, {"Br", 80}, {"Kr", 84}, {"Rb", 85}, {"Sr", 88}, {"Y", 89}, {"Zr", 91},
    {"Nb", 93}, {"Mo", 96}, {"Tc", 98}, {"Ru", 101}, {"Rh", 103}, {"Pd", 106}, {"Ag", 108}, {"Cd", 112}, {"In", 115}, 
    {"Sn", 119}, {"Sb", 122}, {"Te", 128}, {"I", 127}, {"Xe", 131}, {"Cs", 133}, {"Ba", 137}, {"La", 139}, {"Ce", 140}, 
    {"Pr", 141}, {"Nd", 144}, {"Pm", 145}, {"Sm", 150}, {"Eu", 152}, {"Gd", 157}, {"Tb", 159}, {"Dy", 163}, {"Ho", 165}, 
    {"Er", 167}, {"Tm", 169}, {"Yb", 173}, {"Lu", 175}, {"Hf", 178}, {"Ta", 181}, {"W", 184}, {"Re", 186}, {"Os", 190}, 
    {"Ir", 192}, {"Pt", 195}, {"Au", 197}, {"Hg", 201}, {"Tl", 204}, {"Pb", 207}, {"Bi", 209}, {"Po", 209}, {"At", 210}, 
    {"Rn", 222}, {"Fr", 223}, {"Ra", 226}, {"Ac", 227}, {"Th", 232}, {"Pa", 231}, {"U", 238}, {"Np", 237}, {"Pu", 244}, 
    {"Am", 243}, {"Cm", 247}, {"Bk", 247}, {"Cf", 251}, {"Es", 252}, {"Fm", 257}, {"Md", 258}, {"No", 259}, {"Lr", 262}, 
    {"Rf", 267}, {"Db", 270}, {"Sg", 271}, {"Bh", 270}, {"Hs", 277}, {"Mt", 276}, {"Ds", 281}, {"Rg", 280}, {"Cn", 285}, 
    {"Nh", 284}, {"Fl", 289}, {"Mc", 288}, {"Lv", 293}, {"Ts", 294}, {"Og", 294} 
    };
    for(int i = 0; i < x.size(); i++){
        if(x[i] >= '0' && x[i] <= '9'){
            int temp = 0;
            while(i < x.size() && x[i] >= '0' && x[i] <= '9'){
                temp = temp * 10 + (x[i] - '0'); // convert char to int
                i++; // increase i to get the next character
            } 
            i--; // decrease i to avoid skipping the next character  
            s.top() *= temp; // multiply the top of the stack with the number
        // } else if (x[i] == 'H' || x[i] == 'O' || x[i] == 'C' || x[i] == 'S' || x[i] == 'N' || x[i] == 'Ag' ){ 
        //     s.push(K[x[i]]); 
        } else if (x[i] == '('){
            s.push(0); // push 0 to the stack
        } else if (x[i] == ')'){
            int tong = 0;
            while(s.top() != 0){
                tong += s.top();
                s.pop();
            }
            s.pop();
            s.push(tong);
        }      
        else{
            string temp = "";
            temp += x[i];
            if(i + 1 < x.size() && x[i + 1] >= 'a' && x[i + 1] <= 'z'){ // check if the next character is a lowercase letter
                i++; // increase i to get the next character
                temp += x[i]; // add the lowercase letter to the string
            } if(K.find(temp) == K.end()){ 
                cout << "Khong co phan tu hoa hoc nay" << endl;
                return  0;
            }
            s.push(K[temp]);
        }
    }
    int mass = 0;
    while (!s.empty()){
        mass += s.top();
        s.pop();
    }
    return mass;
}

int main(){
    stack<int> s;
    string x;
    cout << "Nhap cong thuc hoa hoc: ";
    cin >> x;
    cout << chemical(s, x);
    return 0;
}

// int main(){
//     map<char, int> K ={
//         {'O', 16},
//         {'H', 1},
//         {'C', 12},
//         {'(', 0}
//     };
//     string x;
//     stack<int> s;
//     cout << "Nhap cong thuc hoa hoc: ";
//     cin >> x;
//     for(char c : x){
//         if(K.find(c) != K.end()){
//             s.push(K[c]);
//     }
//     else if(c == ')'){
//         int t = 0;
//         while(s.top() != 0) t+= s.top(), s.pop();
//         s.top()=t;
//     }
//     else s.top()*=c-'0';

//     int t = 0;
//     while(s.size()) t+=s.top(), s.pop();
//     cout << "Output: " << t << endl;
//     }
// }
