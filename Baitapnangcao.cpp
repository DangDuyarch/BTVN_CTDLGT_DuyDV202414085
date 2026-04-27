#include <iostream>
#include <chrono>

using namespace std;

// Cấu trúc một nút trong danh sách liên kết
struct Node {
    int data;
    Node* link;   };

Node* createCircularList(int n) {
    if (n <= 0) return nullptr;

    Node *head = nullptr;
    Node *tail = nullptr;

    // GIAI ĐOẠN 1: Tạo danh sách liên kết đơn từ 1 đến N
    for (int i = 1; i <= n; i++) {
        // Tạo node mới
        Node* newNode = new Node();
        newNode->data = i;
        newNode->link = nullptr;

        if (head == nullptr) {
            head = newNode; // Nút đầu tiên
            tail = newNode;
        } else {
            tail->link = newNode; // Nối tiếp vào đuôi
            tail = newNode;       // Cập nhật nút đuôi mới
        }
    }

    // GIAI ĐOẠN 2: Nối đầu đuôi để thành vòng tròn (Circular)
    if (tail != nullptr) {
        tail->link = head; 
        // Thay vì trỏ vào nullptr, đuôi trỏ về head để tạo vòng
    }

    return head;
}


void findAndPrintWinner(Node* head, int m) {
    if (head == nullptr) return;

    Node* curr = head;
    Node* prev = nullptr;

    // Tìm nút đứng trước head để lát nữa dễ dàng xóa nút
    Node* temp = head;
    while (temp->link != head) {
        temp = temp->link;
    }
    prev = temp; // prev lúc này là nút cuối cùng (đuôi)

    cout << "Thu tu bi loai: ";
    
    // Vòng lặp dừng khi chỉ còn 1 người (người đó tự trỏ vào chính mình)
    while (curr->link != curr) {
        // 1. Nhảy m bước
        for (int i = 0; i < m; i++) {
            prev = curr;
            curr = curr->link;
        }

        // 2. Loại bỏ người tại vị trí curr
        cout << curr->data << " ";
        prev->link = curr->link; // Nối người trước đó qua người bị loại
        
        Node* toDelete = curr;
        curr = curr->link; // Người kế tiếp giữ bóng cho lượt mới
        delete toDelete;   // Giải phóng bộ nhớ
    }

    cout << "\nNguoi chien thang cuoi cung la: " << curr->data << endl;
    delete curr; // Xóa nút cuối cùng
}


int main() {
    int n, m;
    cout << "Nhap so nguoi N: ";
    cin >> n;
    cout << "Nhap so luot truyen M: ";
    cin >> m;

    // 1. Tạo vòng tròn
    Node* circle = createCircularList(n);

    // 2. Duyệt tìm người thắng cuộc
    findAndPrintWinner(circle, m);

    return 0;
}