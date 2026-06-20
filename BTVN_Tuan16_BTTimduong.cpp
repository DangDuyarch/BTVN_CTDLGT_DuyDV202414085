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


int main() {
        return 0;
}