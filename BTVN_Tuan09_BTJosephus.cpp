#include <iostream>
#include <chrono>

using namespace std;

struct Node {     // Khai bao
    int data;
    Node* link;   };

Node* Taolistvong(int n) {
    if (n <= 0) return nullptr;

    Node *first = nullptr;
    Node *last = nullptr;

    for (int i = 1; i <= n; i++) {     // tao ds don 
        Node* newNode = new Node();
        newNode->data = i;          // truyen so vao danh sach
        newNode->link = nullptr;

    if (first == nullptr) {   // Neu ds trong
            first = newNode;    // them 1 nguoi la dau va cuoi
            last = newNode; } 
        else {
            last->link = newNode;  // Them nguoi neu da co nguo itrong list
            last = newNode;       
        }
    }

    if (last != nullptr) {
        last->link = first;    // Noi thanh ds vong tron
    }

    return first;
}


void Timnguoithang(Node* first, int m) {
    if (first == nullptr) return;   // neu ds trong thi thoi

    Node* p = first;   // nguoi dau tien
    Node* q = nullptr;    // nguo icuoi cung ( truoc p)

    Node* temp = first;            // Tim nguoi dang dung truoc nguoi dau tien
    while (temp->link != first) {
        temp = temp->link;          
    }
    q = temp; // q la nguoi cuoi cung
   // cout << "Nhung nguoi bi loai: ";
    
    while (p->link != p) {     // Neu ds kh chi co 1 nguoi
        for (int i = 0; i < m; i++) {
            q = p;     // danh dau vi tri dung truoc cua con tro dang duyet
            p = p->link;    // chuyen bong
        }
   //     cout << p->data << " ";    // in ra nguoi bi loai
        q->link = p->link;     // Xoa nguoi bi loai
        
        Node* Xoa = p;
        p = p->link; // Nguoi dung dau luot moi
        delete Xoa;   
    }

    cout << "\nNguoi con lai la: " << p->data << endl;
    delete p; // Xoa nguoi cuoi cung
}

int main() {
    int n, m;
    cout << "Nhap so nguoi N: ";
    cin >> n;
    cout << "Nhap so luot truyen M: ";
    cin >> m;
    Node* a = Taolistvong(n); // Tao ds vong tron
    auto start = chrono::high_resolution_clock::now();
    Timnguoithang(a, m); // Duyet tim nguoi cuoi cung
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "\n Thoi gian chay: " << duration.count() << " s" << endl;
    return 0;
}
