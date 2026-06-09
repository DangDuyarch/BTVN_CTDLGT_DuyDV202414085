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

int HeightDiff(AvlNode *t) {   // hàm tính độ lệch tại 1 nút, dùng để kiểm tra 
    if (t == NULL) return 0;
    return height(t->left) - height(t->right);   
}

void insertBST(int x, AvlNode *&t) {      // Hàm để thêm 1 giá trị vào cây nhị phân tìm kiếm
  
    if (t == NULL) {                            // Cây rỗng thì tạo node mới
        t = new AvlNode(x, NULL, NULL, 0);
        return;   }

    if (x < t->elem) {    // chèn cây đảm bảo thứ tự cây nhị phân tìm kiếm
    insertBST(x, t->left);} 

    else if (x > t->elem)  insertBST(x, t->right);   
     else  return;    

    t->height = max(height(t->left), height(t->right)) + 1;// cập nhật lại chiều cao nút sau khi thêm con
} 

bool Checkbalance(AvlNode *t) {    // Hàm kiểm tra xem cây có cân bằng kh
    if (t == NULL) return true;
    
    int balance = HeightDiff(t);
    if (balance > 1 || balance < -1) return false; // Chỉ cần 1 nút không thỏa mãn là cả cây kh cân bằng
    
    return Checkbalance(t->left) && Checkbalance(t->right);
}

// Hàm chạy để in ra kết quả cuối cùng theo ý bạn
void Printcheck(AvlNode *root) {
    if (Checkbalance(root))  cout << "Can bang" << endl;
    else   cout << "Khong can bang" << endl;
}

int main() {
    AvlNode *root = NULL;
    int Tree[] = {32, 51, 27, 83, 96, 11, 45, 75, 66};
    int n = sizeof(Tree) / sizeof(Tree[0]);

    for (int i = 0; i < n; i++) {
        insertBST(Tree[i], root); }

    Printcheck(root);
    return 0;
}