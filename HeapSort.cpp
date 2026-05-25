#include <iostream>
#include <string>
using namespace std;

void Print(int arr[], int n ){          //Hàm in ra mảng 
    cout <<  " [ ";
    for (int i = 0; i < n; i++) {  
    cout << arr[i];
    if (i < n - 1) cout << ", ";    }
    cout << " ]\n"; }

// Vun đống (Vundong)
void Vundong(int arr[], int n, int i) {    // Hàm thay đổi vị trí trong 1 nút, đảm bảo nút cha lớn hơn 2 con
    int Nutcha = i;             // Tạo biến Nutcha để lưu vị trí nút cha đang xét
    int contrai = 2 * i + 1;    // Vị trí của 2 con trái, phải
    int conphai = 2 * i + 2;

if (contrai < n && arr[contrai] > arr[Nutcha])  // Nếu nút cha có gtri nhỏ hơn nút con 
        Nutcha = contrai;             // Cập nhật nút cha thành con có gtri lớn hơn
if (conphai < n && arr[conphai] > arr[Nutcha])
        Nutcha = conphai;

    if (Nutcha != i) {  // Nếu nút cha khác gtri ban đầu
        int b = arr[i];           // Tiến hành đổi chỗ giữa nút cha và nút con có gtri lớn hơn
        arr[i] = arr[Nutcha];    
        arr[Nutcha] = b;
        Vundong(arr, n, Nutcha); // Đệ quy xuống dưới
    }

}

void Taodong(int arr[], int n) {   // Hàm duyệt cây theo thứ tự từ mức thấp nhất, phải nhất, tạo thành đống để cbi xếp
for (int i = n / 2 - 1; i >= 0; i--) {   // Duyệt từ nút cha cuối cùng(n/2 - 1) về đầu mảng
    Vundong(arr, n, i);   // Thay đổi vtri cho từng nút chak
    cout << "Vun dong o nut i = " << i+1 << ":";
    Print(arr, n);    // In ra từng lần vun đốngm
    }
}
void Sapxep(int arr[], int n) {   
    int buoc = 1;           // Chạy từ phần tử cuối cùng (n-1) ngược về 1
    for (int i = n - 1; i > 0; i--) {   
    int b = arr[0];
    arr[0] = arr[i];    // Đổi chỗ giữa nút gốc và ptu cuối cùngk
    arr[i] = b;

    Vundong(arr, i, 0); // Vun đống phần còn lại, kh tính cái vừa đổiz
    Print(arr, n);
    buoc++;
}
}

int main() {
    int arrslide[] = {4, 1, 3, 2, 16, 9, 10, 14, 8 , 7}; // Nhap vào cây trong slide
    int n= sizeof(arrslide) / sizeof(arrslide[0]);    // Tính số ptu của cây

cout << "Xet mang trong slide, mang ban dau:";
Print(arrslide, n);     // In ra mảng ban đầu
cout << "\nCac trang thai luu tru cho moi buoc vun dong: \n";
Taodong(arrslide, n);     // Bước đầu vun đống( theo slide)
cout << "\nCac trang thai luu tru cho moi buoc sap xep vun dong: \n";
Sapxep(arrslide, n);// sap xep, doi cho kmkz
cout << "\nCay sau khi sap xep:";
    Print(arrslide, n);


int arrbang[] = {11, 34, 32, 106, 38, 78, 203, 16, 84, 17, 39 , 15};   // Nhap vao cay tren bảng
int a= sizeof(arrbang) / sizeof(arrbang[0]);

cout << "Xet mang trong slide, mang ban dau:";
Print(arrbang, a);    // in ra mảng ban đầu
cout << "\nCac trang thai luu tru cho moi buoc vun dong: \n";
Taodong(arrbang, a);     // Bước đầu vun đống( theo slide)
cout << "\nCac trang thai luu tru cho moi buoc sap xep vun dong: \n";
Sapxep(arrbang, a);// sap xep, doi cho

cout << "\nCay sau khi sap xep:";
Print(arrbang, a);

    return 0;
}  