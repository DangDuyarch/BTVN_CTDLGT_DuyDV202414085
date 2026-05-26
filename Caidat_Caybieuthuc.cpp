#include <iostream>
#include <string>

using namespace std;

struct Node {       // Cấu trúc một nút trên cây biểu thức
    string data;          // Lưu toán tử,toán hạng
    Node* left;
    Node* right;

    Node(string val) {
    data = val;
    left = nullptr;
    right = nullptr;
    }    };

void Duyettruoc(Node* root) {  //  Duyệt trước theo thứ tự : Gốc -> Trái -> Phải
    if (root == nullptr) return;
    
    cout << root->data << " ";
    Duyettruoc(root->left);
    Duyettruoc(root->right); }


void Duyetgiua(Node* root) {       // 2. Duyệt giữa theo thứ tự: Trái -> Gốc -> Phải
    if (root == nullptr) return;
    if (root->left && root->right) cout << "( "; // Nếu là toán tử thì thêm dấu ngoặc mở
    Duyetgiua(root->left);
    cout << root->data << " ";
    Duyetgiua(root->right);
    if (root->left && root->right) cout << ") ";     // Nếu là toán tử thì thêm dấu ngoặc đóng
    }

void Duyetsau(Node* root) {     // Duyệt sau theo thứ tự: Trái -> Phải -> Gốc
    if (root == nullptr) return;
    Duyetsau(root->left);
    Duyetsau(root->right);
    cout << root->data << " ";
}

int main() {
     //  Dựng thủ công cây biểu thức: (a + b) * (c - d)

    Node* root = new Node("*");
    root->left = new Node("+");
    root->left->left = new Node("a");
    root->left->right = new Node("b");
    root->right = new Node("-");
    root->right->left = new Node("c");
    root->right->right = new Node("d");

    cout << "Duyet truoc  ";
    Duyettruoc(root);
    cout << endl;
    cout << "Duyet giua  ";
    Duyetgiua(root);
    cout << endl;
    cout << "Duyet sau  ";
    Duyetsau(root);
    cout << endl;

    delete root->left->left;     // Giải phóng bộ nhớ 
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
