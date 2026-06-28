
// sử dụng code tuàn 16 để khai báo ma trận đỉnh kề, theo slide 

#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;

const int Sotinh_max = 11;
const int INF = 1e9;    

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

struct CanhChon {  
     int u, v;   };

void ThuatToanPrim(Matran &g) {
    int n = g.Sotinhxet;
    bool Daduyet[Sotinh_max] = {false};  // Mang danh dau tinh da duyet ( nam trong cay)
    Daduyet[9] = true;     // Duyet tu Ha Noi

    CanhChon dsCanh[Sotinh_max];
    int soCanh = 0;

    for (int i = 0; i < n - 1; i++) { // n đinh, duyet n-1 lân
        int trso_min = INF;
        int u_min = -1, v_min = -1;  // bien danh dau

    for (int i = 0; i < n; i++) {
        if (Daduyet[i]) {   // Duyet cac dinh da nam trong cay khung
            for (int j = 0; j < n; j++) {  
            if (!Daduyet[j] && g.matrix[i][j] > 0 && g.matrix[i][j] < trso_min) { 
            // cac dinh co duong di, chua nam trong cay và co duong di ngan hơn duong min
                trso_min = g.matrix[i][j];    // cap nhat lai trong so nho nhat
                u_min = i;
                v_min = j; }  // danh dau cap dinh ngan nhat
             } }
        }
    if (u_min != -1 && v_min != -1) { // nếu tim duoc duong di moi
        cout << "Chon canh " << DSTinh[u_min] << " -> " << DSTinh[v_min] << " = " << trso_min << endl;
        Daduyet[v_min] = true;     // Kết nạp đỉnh mới vào cây
        dsCanh[soCanh++] = {u_min, v_min};   }   // lưu vào mảng để in ra kq
    else  break;    } 

    cout << "\nCay khung nho nhat: ";
    for (int i = 0; i < soCanh; i++) {
        cout << DSTinh[dsCanh[i].u] << " -> " << DSTinh[dsCanh[i].v]; // in ra cac canh vua chon
        if (i < soCanh - 1) {
            cout << ", "; // them , và tao khoang cach cho dep
        }
    }
    cout << endl;


}

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

    ThuatToanPrim(g);

    return 0;
}

