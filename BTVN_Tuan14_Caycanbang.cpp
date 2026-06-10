#include <iostream>
#include <algorithm>
using namespace std;

struct AvlNode {
    int elem;          //  giá trị của nút
    AvlNode *left;      // con trỏ nút con trái, phải
    AvlNode *right;   
    int height;        // Chiều cao của nút

AvlNode(int e, AvlNode *l, AvlNode *r, int h)  // Hàm khởi tạo nhanh một nút mới
    {   elem = e;
        left = l;
        right = r;
        height = h;   }  
};

int height(AvlNode *t){     // Hàm trả về chiều cao của nút, nút rỗng cao -1 
    return t == NULL ? -1 : t->height;    
}

int HeightDiff(AvlNode *t) {   // hàm tính độ lệch tại 1 nút, dùng để kiểm tra xem có cần xoay hay không
    if (t == NULL) return 0;
    return height(t->left) - height(t->right);   
}

void rotateWithLeftChild(AvlNode *&k2) {  // Hàm xoay đơn trái, gọi k2 là nút cha mất cân bằng, k1 là con trái của k2
    AvlNode *k1 = k2->left;     // Giữ địa chỉ của k1 để xoay
    k2->left = k1->right;     // lấy con phải k1 gán thành con trái k2, như slide
    k1->right = k2;    // gán k2 thành con phải của k1 
    
    k2->height = max(height(k2->left), height(k2->right)) + 1;  // cập nhật chiều cao k2, cập nhật chiều cao từ con tới cha để đảm bảo
    k1->height = max(height(k1->left), k2->height) + 1;  // cập nhật chiều cao k1 
    
    k2 = k1; // Đổi gốc của cây con thành k1
}

void rotateWithRightChild(AvlNode *&k1) {  // Tương tự hàm trên nhưng xoay sang phải
    AvlNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
}

void doubleWithLeftChild(AvlNode *&k3) { // Con mới thêm vào bên phải con trái của k3 gây lệch, thao tác như sld
    rotateWithRightChild(k3->left);   // Xoay phải cho con trái k3
    rotateWithLeftChild(k3);   // xoay trái k3
}

void doubleWithRightChild(AvlNode *&k1) {     // Tương tự hàm trên nhưng xoay trái cho con phải k1, xong xoay trái k1 
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

void insertBST(int x, AvlNode *&t) {      // Hàm để thêm 1 giá trị vào cây nhị phân tìm kiếm, đảm bảo cân bằng AVL bằng xoay đơn
  
    if (t == NULL) {                            // Ktra cây rỗng thì tạo node mới
        t = new AvlNode(x, NULL, NULL, 0);
        return;   }

    if (x < t->elem) {  insertBST(x, t->left);}   // chèn cây đảm bảo thứ tự cây nhị phân tìm kiếm
    
    else if (x > t->elem)  insertBST(x, t->right);   
    else  return;    

    t->height = max(height(t->left), height(t->right)) + 1;// cập nhật lại chiều cao nút sau khi thêm con
    int balance = HeightDiff(t);  // Kiểm tra độ lệch của 2 con tại nút hiện tại, nếu lệch quá +-1 thì xoay để cân bằng 

   // Kiểm tra xem cây bị lệch theo trường hợp nào để xoay 
    if (balance > 1) {     // cây lệch trái, bên trái sâu hơn 
        if (x < t->left->elem) {    // con mưới nằm bên trái của con trái gây lệch thì xoay đơn phải 
            rotateWithLeftChild(t); }
        else {      // con mới nằm bên phải của con trái gây lệch thì xoay kép trái phải 
            doubleWithLeftChild(t);    }      }

    else if (balance < -1) {        // Cây lệch bên phải 
        if (x > t->right->elem) {      // con mới nằm bên phải của con phải gây lệch thì xoay đơn trái
          rotateWithRightChild(t);} 
          else {      // con mới nằm bên trái của conphải gây lệch thì xoay kép phải trái
        doubleWithRightChild(t); }   }
}


bool Checkbalance(AvlNode *t) {    // Hàm kiểm tra xem cây có cân bằng kh
    if (t == NULL) return true;
    
    int balance = HeightDiff(t);
    if (balance > 1 || balance < -1) return false; // Chỉ cần 1 nút không thỏa mãn là cả cây kh cân bằng
    
    return Checkbalance(t->left) && Checkbalance(t->right); // Đệ quy ktra cả 2 con 
    }

void Printcheck(AvlNode *root) {    // Hàm chạy để in ra kết quả cuối cùng 
    if (Checkbalance(root))  cout << "Can bang" << endl;
    else   cout << "Khong can bang" << endl;
}

int main() {
    AvlNode *root = NULL;
    int Tree[] = {50, 20, 70, 10, 30, 25};
    int n = sizeof(Tree) / sizeof(Tree[0]);

    for (int i = 0; i < n; i++) {
        insertBST(Tree[i], root); }

    Printcheck(root);
    return 0;
}