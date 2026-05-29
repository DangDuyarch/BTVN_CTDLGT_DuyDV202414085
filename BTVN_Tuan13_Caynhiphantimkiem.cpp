// Bài tập dựng cây nhị phân tìm kiếm, yêu cầu tạo hàm thêm node vào cây theo quy tắc, tìm 1 giá trị thỏa mãn xem có tồn tại trong cây nhị phân hay kh

// Cài đặt cây nhị phân bằng lưu trữ kế tiếp, các node rỗng được biểu diễn bởi gtri 0.

// Quy tắc lập cây nhị phân hiện tại là: nếu nhỏ hơn hoặc bằng node hiện tại thì thêm vào con bên trái, nếu lớn hơn nút hiện tại thì bên phải

#include <iostream>
#include <cmath>
using namespace std;

void add_nodeBST(int tree[], int max, int a) {    // Hàm thêm node vào cây nhị phân theo quy tắc 
    int i = 0;                                  
    while (i < max) {              
        if (tree[i] == 0)  // Thêm giá trị vào node rỗng
        { tree[i] = a;
            return;  }
        if (a <= tree[i])  i = 2 * i + 1;        // Nếu a nhỏ hơn node hiện tại đan xét -> xét sang con bên trái
        else if (a > tree[i]) i = 2 * i + 2;    // Nếu a lớn hơn thì xét sang phải
        else return;
    }
}


void initial_BST(int arr[], int n, int tree[], int max) {    // Hàm dựng cây nhị phân tìm kiếm theo yêu cầu 
    for (int i = 0; i < n; i++) {
        add_nodeBST(tree, max, arr[i]);    // Thêm từng ptu trong mảng vào cây nhị phân bằng hàm có sẵn
    }    }



void search_BST(int tree[], int max, int find) {    // Hàm tìm kiếm 1 giá trị trong cây nhị phân 
    int i = 0; 
    while (i < max) {      // tạo vòng lặp từ đàu đến cuối cây 

    if (tree[i] == 0) {  cout << "Khong tim thay gia tri " << find << " trong cay tim kiem nhi phan" <<  endl;   // Kh thấy thì in ra thông báo tương tự
            return; }
    if (tree[i] == find) { cout << "Tim thay gia tri " << find << " tai vi tri: " << i << endl;  // Tìm thấy cũng in ra thông báo tương tự
            return;   }


    if (find <= tree[i]) {  // Nếu giá trị cần tìm lớn hơn nút hiện tại -> Rẽ sang phải
        i = 2 * i + 1;  }
    else { i = 2 * i + 2; }  // ngược lại thì sang trái
}
    cout << "Khong tim thay gia tri " << find << " trong cay tim kiem nhi phan" <<  endl;   // Lặp hết mà kh thấy thì in ra kh thấy
}


void Print_BST(int tree[], int max) {      // Hàm in cây từ đầu đến node cuối cùng khác rỗng 
    int p = -1;
    for (int i = max - 1; i >= 0; i--) {     // Tìm ptu cuối cùng có nghĩa
        if (tree[i] != 0) { p = i;   break;  }  } // Tìm phần tử khác rỗng cuối cùng và lưu vị trí

    for (int i = 0; i <= p; i++) {   cout << tree[i] << " "; }       // In cây từ đầu đến vtri đó
    cout << endl;
}


int main() {
    int arr[] = {2001,2002,2006,2007,2003,2004,2005,2001,1999,2004};
    int n = sizeof(arr) / sizeof(arr[0]);    
    int max = pow(2,n)-1;    // Tính số node tối đa của cây nhị phân làm từ các gtri trong mảng
    int tree[max] = {0};

    initial_BST(arr, n, tree, max);
    Print_BST(tree, max);

    add_nodeBST(tree, max, 1777);       // thêm ptu vào cây nhị phân tìm kiếm
    Print_BST(tree, max);

    search_BST(tree, max, 2004); 
    search_BST(tree, max, 1111);

    return 0;
}

