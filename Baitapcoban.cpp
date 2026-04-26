#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Ngay     // Khai bao cau truc ngay
  {
	int ngay, thang, nam;
  };

struct SinhVien   // Khai bao cau truc sinh vien
  {
	char maSV[10];
	char hoTen[50];
	int gioiTinh;
	Ngay ngaySinh;
	char diaChi[100];
	char lop[12];
	char khoa[7];
   };

struct Node    // Khai bao node
{
	SinhVien data;
	Node *link;
};
struct List     // Khai bao danh sach
{
 	Node *first;
	Node *last;
};


void ThemSV(Node*& head, SinhVien newSVData) {     // 1. Tạo Node mới và gán dữ liệu
    
    Node* Newnode = new Node;
    Newnode->data = newSVData;
    Newnode->link = nullptr;

    // 2. Trường hợp danh sách rỗng hoặc MSSV mới nhỏ hơn MSSV đầu tiên
    // strcmp(a, b) < 0 nghĩa là chuỗi a nhỏ hơn chuỗi b về mặt từ điển
    if (head == nullptr || strcmp(newSVData.maSV, head->data.maSV) < 0) {
        Newnode->link = head;
        head = Newnode;
        return;
    }

    // 3. Tìm vị trí để chèn sao cho danh sách vẫn giữ thứ tự tăng dần MSSV
    Node* p = head;
    while (p->link != nullptr && strcmp(p->link->data.maSV, newSVData.maSV) < 0) {
        p = p->link;
    }

    // 4. Thực hiện chèn node mới vào sau node p
    Newnode->link = p->link;
    p->link = Newnode;
}

void InSVCungNgaySinh(Node* head) {
    bool foundGlobal = false;
    Node* p = head;

    while (p != nullptr) {
        bool foundGroup = false;
        Node* q = p->link;
        
        // Kiểm tra xem ngày sinh của p đã được in trong một nhóm trước đó chưa
        // (Để tránh in lặp lại cùng một nhóm sinh viên)
        bool alreadyPrinted = false;
        Node* check = head;
        while (check != p) {
            if (check->data.ngaySinh.ngay == p->data.ngaySinh.ngay &&
                check->data.ngaySinh.thang == p->data.ngaySinh.thang &&
                check->data.ngaySinh.nam == p->data.ngaySinh.nam) {
                alreadyPrinted = true;
                break;
            }
            check = check->link;
        }

        if (!alreadyPrinted) {
            // Tìm các node q đứng sau p có cùng ngày sinh
            Node* tempQ = q;
            while (tempQ != nullptr) {
                if (tempQ->data.ngaySinh.ngay == p->data.ngaySinh.ngay &&
                    tempQ->data.ngaySinh.thang == p->data.ngaySinh.thang &&
                    tempQ->data.ngaySinh.nam == p->data.ngaySinh.nam) {
                    if (!foundGroup) {
                        cout << "\nCac sinh vien cung ngay sinh " << p->data.ngaySinh.ngay << "/" << p->data.ngaySinh.thang << ":" << endl;
                        cout << "- " << p->data.hoTen << " (" << p->data.maSV << ")" << endl;
                        foundGroup = true;
                        foundGlobal = true;
                    }
                    cout << "- " << tempQ->data.hoTen << " (" << tempQ->data.maSV << ")" << endl;
                }
                tempQ = tempQ->link;
            }
        }
        p = p->link;
    }

    if (!foundGlobal) {
        cout << "Khong tim thay sinh vien cung ngay sinh" << endl;
    }
}

// Hàm in danh sách đơn giản
void InDanhSach(Node* head) {
    cout << "------------------------------------------" << endl;
    cout << "MSSV\tHo Ten\t\tLop" << endl;
    Node* p = head;
    while (p != nullptr) {
        cout << p->data.maSV << "\t" 
             << p->data.hoTen << "\t" 
             << p->data.lop << endl;
        p = p->link;
    }
    cout << "------------------------------------------" << endl;
}

int main() {
    Node* head = nullptr; 
    // Thêm vào (hàm ThemSV sẽ tự sắp xếp theo MSSV)
// Danh sach 8 sinh vien voi MSSV 8 so (dang 2024xxxx)
// Danh sach 8 sinh vien voi MSSV 9 so
    ThemSV(head, {"202414405", "Tran Hoang Hai", 1, {10, 1, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(head, {"202414406", "Nguyen Duc Duy", 1, {15, 2, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(head, {"202414401", "Nguyen Duc Kien", 1, {20, 3, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(head, {"202414413", "Ha Dang Quang", 1, {5, 4, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(head, {"202414203", "Van Thanh Dat", 1, {12, 5, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(head, {"202414073", "Nguyen Khanh Huyen", 0, {25, 6, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(head, {"202414074", "Le Khanh Linh", 0, {25, 6, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(head, {"202414063", "Nguyen Manh Thien", 1, {30, 7, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(head, {"202414058", "Tran Duc Manh", 1, {30, 7, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(head, {"202414365", "Nguyen Quoc Huy", 1, {30, 7, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(head, {"202414103", "Hoang Lam Que", 0, {18, 8, 2006}, "HN", "DT05", "SEEE"});

cout << "\nDang thuc hien xoa sinh vien trung ngay sinh..." << endl;
    InSVCungNgaySinh(head);

    // In ra kết quả
    cout << "Danh sach sinh vien sau khi sap xep:" << endl;
    InDanhSach(head);

    return 0;
}