#include <iostream>
#include <string>

using namespace std;

// Cấu trúc một nút trên cây biểu thức
struct Node {
    string data; // Lưu toán tử hoặc toán hạng
    Node* left;
    Node* right;

    Node(string val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// 1. Duyệt trước (Pre-order): Gốc -> Trái -> Phải
void printPreOrder(Node* root) {
    if (root == nullptr) return;
    
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// 2. Duyệt giữa (In-order): Trái -> Gốc -> Phải
// Thêm dấu ngoặc đơn để biểu thức trung tố rõ ràng, dễ nhìn hơn
void printInOrder(Node* root) {
    if (root == nullptr) return;

    // Nếu là toán tử (không phải nút lá), thêm dấu ngoặc mở
    if (root->left && root->right) cout << "( ";

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);

    // Nếu là toán tử, thêm dấu ngoặc đóng
    if (root->left && root->right) cout << ") ";
}

// 3. Duyệt sau (Post-order): Trái -> Phải -> Gốc
void printPostOrder(Node* root) {
    if (root == nullptr) return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main() {
    /*
            Biểu diễn biểu thức: (a + b) * (c - d)
            
                     *
                   /   \
                  +     -
                 / \   / \
                a   b c   d
    */

    // Dựng thủ công cây biểu thức như sơ đồ trên
    Node* root = new Node("*");
    
    root->left = new Node("+");
    root->left->left = new Node("a");
    root->left->right = new Node("b");

    root->right = new Node("-");
    root->right->left = new Node("c");
    root->right->right = new Node("d");

    // Xuất kết quả
    cout << "--- KET QUA DUYET CAY BIEU THUC ---" << endl;

    cout << "1. Duyet truoc (Prefix): ";
    printPreOrder(root);
    cout << endl;

    cout << "2. Duyet giua (Infix):  ";
    printInOrder(root);
    cout << endl;

    cout << "3. Duyet sau (Postfix): ";
    printPostOrder(root);
    cout << endl;

    // Giải phóng bộ nhớ (đơn giản)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}