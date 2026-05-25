#include <iostream>
#include <string>
using namespace std;

void Print(int arr[], int n ){          //Hàm in ra mảng 
    cout <<  " [ ";
    for (int i = 0; i < n; i++) {  
    cout << arr[i];
    if (i < n - 1) cout << ", ";    }
    cout << " ]\n"; }

// Vun đống (Hoandoi)
void Hoandoi(int arr[], int n, int i) {    // Hàm thay đổi vị trí trong 1 nút, đảm bảo nút cha lớn hơn 2 con
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
        Hoandoi(arr, n, Nutcha); // Đệ quy xuống dưới
    }

}

void Vundong(int arr[], int n) {   // Hàm duyệt cây theo thứ tự từ mức thấp nhất, phải nhất
for (int i = n / 2 - 1; i >= 0; i--) {   // Duyệt từ nút cha cuối cùng(n/2 - 1) về đầu mảng
    Hoandoi(arr, n, i);   // Thay đổi vtri cho từng nút cha
    cout << "Vun dong o nut i = " << i << ":";
    Print(arr, n);    // In ra từng lần vun đống 
    }
}

int main() {
    int arr[] = {11, 54, 32, 106, 38, 78, 203, 16, 84, 17, 39, 15};  // Ví dụ trên bảng
    int n = sizeof(arr) / sizeof(arr[0]);    // Số ptu của mảng

    Print(arr, n);
    cout << "\n";

    Vundong(arr, n);

    cout << "\n Ket qua: ";

    Print(arr, n);

    return 0;
}