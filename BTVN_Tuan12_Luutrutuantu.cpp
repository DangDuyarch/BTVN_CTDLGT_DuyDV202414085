// Cài đặt cấu trúc cây cấu trúc lưu trữ tuần tự, gốc của cây mang thứ tự 0, khác với tlieu slide là 1

#include <iostream>
using namespace std;

#define MAX_NODES 100     
#define MAXLENGTH 100     // so ptu tối đa của cây là 100
#define NIL -1            // nut rỗng

typedef int DataType;
typedef int Node;

typedef struct {
    DataType Data[MAXLENGTH]; // Lưu giá trị của nút
    int MaxNode;              
} Tree;        // tạo kiểu dl để lưu trữ cây


int EmptyTree(Tree T)     // Ktra cây rỗng
{      
    return T.MaxNode == 0;  }

Node Root(Tree T) {        // Xác định nút gốc trong cây
    if (!EmptyTree(T))        return 0;        // Nếu cây kh rỗng thì nút gốc luôn nằm ở vtri 0
    else                      return NIL;  // cây rỗng thì trả về NIL   
}

int Left_Child(Node p) {   // Hàm xđ vtri con trái của nút p
 if (p == NIL) return NIL;   
    return 2 * (p + 1) - 1;  // Vị trí nút con trái của nút vtri p theo slide: 2*(p+1) - 1
}       

int Right_Child(Node p) {   // Hàm xđ vtri con trái của nút p, như nút trái
if (p == NIL) return NIL; // công thức: 2*(p+1)
    return 2 * (p + 1);    
}

void InitTree(Tree &T) { // hàm khởi tạo cây rỗng
    T.MaxNode = 0;
    for (int i = 0; i < MAXLENGTH; i++) {
        T.Data[i] = NIL;       //các vtri ban đầu đều là NIL 
    }      }


// Duyet và in cây theo thứ tự lưu trữ kế tiếp
void Printtree(Node p, Tree T) {
    if (p == NIL || p >= T.MaxNode) {  // Dừng nếu vượt ranh giới 
        return; 
    }
//  Nếu vị trí p hợp lệ nhưng ô mảng đó mang giá trị trống -> In số 0
    if (T.Data[p] == NIL) {  
    cout << "0 "; // Nếu ô trống thì in số 0
     }   
    
    else {     cout << T.Data[p] << " ";    }   // Nếu ô mảng đó có dữ liệu -> In giá trị của nút
    Printtree(Left_Child(p), T);        // De quy voi con trái trước
    Printtree(Right_Child(p), T);       // De quy con phải sau 
}

int main() {

    Tree Tziczac;
    InitTree(Tziczac); 
    Tziczac.Data[0]  = 1;  
    Tziczac.Data[1]  = 2;     // Nhap dl cây ziczac
    Tziczac.Data[4]  = 3;  
    Tziczac.Data[9]  = 4;  
    Tziczac.Data[20] = 5;  
    Tziczac.MaxNode = 21;

    cout << "Cay Zic-zac : ";
    Printtree(Root(Tziczac), Tziczac);
    cout << endl << endl; 

    Tree TLeft;
    InitTree(TLeft);
    TLeft.Data[0]  = 1;  
    TLeft.Data[1]  = 2;  
    TLeft.Data[3]  = 3;  // Nhap dl cay lẹch trai
    TLeft.Data[7]  = 4;  
    TLeft.Data[15] = 5;  
    TLeft.MaxNode = 16;  

    cout << "Cay lech trai :  ";
    Printtree(Root(TLeft), TLeft);  // in ra cay lech trai
    cout << endl << endl;

    Tree TRight;
    InitTree(TRight);
    TRight.Data[0]  = 1; 
    TRight.Data[2]  = 2;       // in ra cay lech phai
    TRight.Data[6]  = 3;  
    TRight.Data[14] = 4;  
    TRight.Data[30] = 5;  
    TRight.MaxNode = 31;  

    cout << "Cay lech phai :  ";
    Printtree(Root(TRight), TRight);
    cout << endl;

    return 0;
}
