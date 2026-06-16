#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int Sotinh_max = 11;
const string vertexNames[Sotinh_max] = {
    "Ha Noi", "Thai Nguyen", "Bac Ninh", "Bac Giang",
    "Uong Bi", "Hai Phong", "Hai Duong", "Hung Yen", "Phu Ly", "Hoa Binh", "Son Tay"
};

struct Matran {
    int Sotinhxet;
    int matrix[Sotinh_max][Sotinh_max];
};

void Khoitaomatran(Matran &g, int n) {
    g.Sotinhxet = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g.matrix[i][j] = 0;
        }
    }
}

struct Nut {
    int maTuyenTinh;    
    Nut* tiepTheo;      
};

struct DanhSachDoThi {
    int Sotinhxet;
    Nut* dau[Sotinh_max]; 
};

void Khoitaods(DanhSachDoThi &dt, int n) {
    dt.Sotinhxet = n;
    for (int i = 0; i < n; i++) {
        dt.dau[i] = nullptr;
    }
}

int main() {
    return 0;}