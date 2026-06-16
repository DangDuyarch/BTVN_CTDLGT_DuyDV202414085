#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int Sotinh_max = 11;    // khai bao 11 tinh theo de bai
const string DSTinh[Sotinh_max] = {     // 11 tinh thoe bai
    "Ha Noi", "Thai Nguyen", "Bac Ninh", "Bac Giang",
    "Uong Bi", "Hai Phong", "Hai Duong", "Hung Yen", "Phu Ly", "Hoa Binh", "Son Tay"
};

struct Matran {   // khai báo
    int Sotinhxet;
    int matrix[Sotinh_max][Sotinh_max];
};

void Khoitaomatran(Matran &g, int n) { // tạo mtr trống (0)
    g.Sotinhxet = n;
    for (int i = 0; i < n; i++) {     // mtr trống
        for (int j = 0; j < n; j++)  g.matrix[i][j] = 0; }
}

void ThemDuongMaTran(Matran &g, int u, int v) {
    g.matrix[u][v] = 1;
    g.matrix[v][u] = 1; }




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

void ThemDuongDanhSach(DanhSachDoThi &dt, int u, int v) {
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

int main() {
    Matran g;
    Khoitaomatran(g, 3);
    cout << "Truoc khi them duong (HN-TN): " << g.matrix[0][1] << endl;
    ThemDuongMaTran(g, 0, 1); 
    
    cout << "Sau khi them duong: " << endl;
    cout << "Ha Noi -> Thai Nguyen: " << g.matrix[0][1] << endl;
    cout << "Thai Nguyen -> Ha Noi: " << g.matrix[1][0] << endl;
    
    return 0;
}