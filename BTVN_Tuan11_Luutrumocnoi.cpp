#include <iostream>
#include <iomanip>

// De bai yeu cau cai dat 3 cay theo cau truc moc noi, phan in ra la bo sung them


using namespace std;

struct Node {     // dinh nghiea 1 cautruc nut
    int data;     
    Node* left;   
    Node* right; 

    Node(int val) {  // val la gia tri duoc them vao
    data = val;
    left = nullptr;   // khoi tao con trai, con phai 
    right = nullptr;
    }
};
Node* TLeft() {        // Cai dat thu cong cay lẹch trái
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->left->left->left->left = new Node(5);
    return root;
}

Node* TRight() {    // Cai dat thu cong cay lech phai
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->right->right = new Node(4);
    root->right->right->right->right = new Node(5);
    return root;
}

Node* Tziczac() {     // Cai dat thu cong cay ziczac
    Node* root = new Node(1);
    root->left = new Node(2);        
    root->left->right = new Node(3); 
    root->left->right->left = new Node(4); 
    root->left->right->left->right = new Node(5); 
    return root;
}

void PrintTree(Node* root, int space = 0) {    // Bo sung ham mo ta cay bang hinh ve
    if (root == nullptr) return;

    space += 8;
    PrintTree(root->right, space);

    cout << endl;
    for (int i = 8; i < space; i++) cout << " ";  // ỉn ra theo thu tu tu trai sang phai thay vi tren xuong duoi
    
    cout <<  root->data  << "\n";
    PrintTree(root->left, space);
}


int main() {

    cout << "\n CAY LECH TRAI";
    Node* leftSkewed = TLeft();
    PrintTree(leftSkewed);

    cout << "\nCAY LECH PHAI";
    Node* rightSkewed = TRight();
    PrintTree(rightSkewed);

    cout << "\nCAY ZIGZAC";
    Node* zigzag = Tziczac();
    PrintTree(zigzag);

    return 0;
}
