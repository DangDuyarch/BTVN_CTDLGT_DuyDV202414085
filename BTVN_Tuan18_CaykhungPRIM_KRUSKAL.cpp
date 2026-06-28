// sử dụng code tuàn 16 để khai báo ma trận đỉnh kề, theo slide 
#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;
const int Sotinh_max = 11;    
const string DSTinh[Sotinh_max] = { "HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST" }; 

struct Matran {   // khai báo
    int Sotinhxet;
    int matrix[Sotinh_max][Sotinh_max];
};

void Khoitaomatran(Matran &g, int n) { // tạo mtr trống (0)
    g.Sotinhxet = n;
    for (int i = 0; i < n; i++) {     // mtr trống
        for (int j = 0; j < n; j++)  g.matrix[i][j] = 0; }
}

void ThemDuongMaTran(Matran &g, int u, int v, int matuyen) {
    g.matrix[u][v] = matuyen;  
    g.matrix[v][u] = matuyen; }

// ham in ma tran
void Inmatran(int P[Sotinh_max][Sotinh_max], int n) {
    cout << setw(6) << " ";
    for (int j = 0; j < n; j++) { cout << setw(5) << DSTinh[j]; }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(6) << DSTinh[i];
        for (int j = 0; j < n; j++)    cout << setw(5) << P[i][j];
        cout << endl;
    }  }


int main() {
    int n = Sotinh_max;
    Matran g; 
    Khoitaomatran(g, n);
    // Nhap du lieu tu do thi cac tinh trong slide, quy doi mã đường đi sang khoảng cách
int CacTuyenDuong[][3] = { {0, 6, 1}, {6, 7, 2}, {8, 7, 3}, {0, 8, 4}, {0, 9, 5},   
    {0, 10, 6},{0, 1, 7}, {0, 2, 8}, {2, 3, 9}, {3, 4, 10}, {2, 4, 11},  {4, 5, 12}, {6, 5, 13}   };
    int soTuyen = sizeof(CacTuyenDuong) / sizeof(CacTuyenDuong[0]);
    
    for(int i = 0; i < soTuyen; i++) { 
    ThemDuongMaTran(g, CacTuyenDuong[i][0], CacTuyenDuong[i][1], CacTuyenDuong[i][2]);}
    cout << "             Ma tran ban dau" << endl ; 
    Inmatran(g.matrix, n);

    return 0;
}

