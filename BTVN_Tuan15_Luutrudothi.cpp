#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;

const int Sotinh_max = 11;    // khai bao 11 tinh theo de bai
const string DSTinh[Sotinh_max] = {     // 11 tinh thoe bai
    "HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST"};
// Các ký hiệu tương đương : Hà Nội, Thái Nguyên, Bắc Ninh,... theo đề bài

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
    g.matrix[u][v] = matuyen;  // cap nhat lai, khph ton tai ma la tuyen duong
    g.matrix[v][u] = matuyen; }



struct Nut {       // Định nghĩa node
    int maTuyenTinh;    
    Nut* tiepTheo;      };

struct DanhSachDoThi {   // Định nghĩa ds lien ke
    int Sotinhxet;
    Nut* dau[Sotinh_max]; };

void Khoitaods(DanhSachDoThi &dt, int n) {  // DS trống (null)
    dt.Sotinhxet = n;
    for (int i = 0; i < n; i++)  dt.dau[i] = nullptr;
}

void ThemDuongDanhSach(DanhSachDoThi &dt, int u, int v, int maTuyen) { // bo sung
   // ham ket noi 2 node u voi v, tinh u co duogn den v và ngược lại
    Nut* nutMoi1 = new Nut;     // Thêm v vào danh sách của u
    nutMoi1->maTuyenTinh = v;
    nutMoi1->tiepTheo = dt.dau[u];
    dt.dau[u] = nutMoi1;

    Nut* nutMoi2 = new Nut;   // Thêm u vào danh sách của v 
    nutMoi2->maTuyenTinh = u;
    nutMoi2->tiepTheo = dt.dau[v];
    dt.dau[v] = nutMoi2;
}


void InMaTran(Matran g) {
    cout << setw(15) << " ";
  for (int j = 0; j < g.Sotinhxet; j++) {   cout << setw(15) << DSTinh[j]; }  // in ten tỉnh theo hàng
    cout << endl;

    for (int i = 0; i < g.Sotinhxet; i++) {
        cout << setw(15) << DSTinh[i];   // in ten tinh theo cột
        for (int j = 0; j < g.Sotinhxet; j++) {
            if (g.matrix[i][j] == 0)  cout << setw(15) << "0";   // kh co đường đi
            else {
                string tenDuong = "D" + to_string(g.matrix[i][j]);
                cout << setw(15) << tenDuong; } }    // In ra mã đường
        cout << endl;
    }   }

int main() {
    int n = Sotinh_max;
    Matran g; 
    Khoitaomatran(g, n);
    DanhSachDoThi dt; 
    Khoitaods(dt, n);

  
    int CacTuyenDuong[][3] = { {0, 6, 1},  {6, 7, 2}, {7, 8, 3},  {0, 8, 4}, {0, 9, 5},   
        {0, 10, 6}, {0, 1, 7},  {0, 2, 8},  {2, 3, 9}, {3, 4, 10},  {2, 4, 11},  {4, 5, 12},{6, 5, 13}  };
// Nạp dữ liệu vào cấu trúc ma trận 

    int soTuyen = sizeof(CacTuyenDuong) / sizeof(CacTuyenDuong[0]);
    for(int i = 0; i < soTuyen; i++) { ThemDuongMaTran(g, CacTuyenDuong[i][0], CacTuyenDuong[i][1], CacTuyenDuong[i][2]);}


    InMaTran(g);
    return 0;
}