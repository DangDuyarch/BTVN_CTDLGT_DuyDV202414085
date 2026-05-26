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

void ThemSV(List &List, SinhVien newSVData) {
    Node* Newnode = new Node;       // Tao node
    Newnode->data = newSVData;   // Gan data cho node moi
    Newnode->link = nullptr;

    if (List.first == nullptr || strcmp(newSVData.maSV, List.first->data.maSV) < 0) {  // Kiem tra ds co trong hoac co the chen node moi vào dau
    Newnode->link = List.first;
    List.first = Newnode;              // Chen vao dau tien neu ds dang rong...
    return; }

    Node* p = List.first;
    while (p->link != nullptr && strcmp(p->link->data.maSV, newSVData.maSV) < 0) {  p = p->link;   }                        // Tim vi tri chen
    Newnode->link = p->link;                // Chen node
    p->link = Newnode;
}

void XoaSV(Node*& first, Node* SVDelete) {
    if (first == nullptr || SVDelete == nullptr) return; // ktra xem ds co trong kh

    if (first == SVDelete) {   // Xoa neu sv o dau danh sach
        first = first->link;
        delete SVDelete;
        return; }

    Node* p = first;
    while (p->link != nullptr && p->link != SVDelete) {  p = p->link;     }   // Tim vi tri nguoi dung truoc sv can xoa 

    if (p->link == SVDelete) {
        p->link = SVDelete->link;   // Xoa node chua dl sinh vien
        delete SVDelete; }
}

void TimXoaSV(Node*& first) {
    Node* p = first;
    bool DSCotrung = false;

    while (p != nullptr) {
    Node* trung = nullptr;
        
    for (Node* q = first; q != nullptr; q = q->link) {    // Do tim xem co ai trung ngay sinh kh
         if (p != q &&  p->data.ngaySinh.ngay == q->data.ngaySinh.ngay && p->data.ngaySinh.thang == q->data.ngaySinh.thang &&  p->data.ngaySinh.nam == q->data.ngaySinh.nam) 
        {  trung = q; // Tim thay nguoi trung ngay sinh
                break;
            }
        }

        if (trung != nullptr) {
            Ngay Ngaysinhtrung = p->data.ngaySinh;        // Khai bao bien ngay can xoa la ngay sinh bi trung
            DSCotrung = true;

            Node* r = first;      // Khai bao 1 bien de tim nhung nguoi cung ngay sinh do
            while (r != nullptr) {
                if (r->data.ngaySinh.ngay == Ngaysinhtrung.ngay &&  r->data.ngaySinh.thang == Ngaysinhtrung.thang &&  r->data.ngaySinh.nam == Ngaysinhtrung.nam)
                { cout << r->data.hoTen << " (Ngay sinh: " << Ngaysinhtrung.ngay << "/" << Ngaysinhtrung.thang << ")" << endl;    // In ra nhung nguoi cung ngay sinh
                    
                    Node* SVcanxoa = r;
                    r = r->link;          
                    XoaSV(first, SVcanxoa);      // Xoa nguoi trung ngay sinh
                } else { r = r->link;  } // Khong trung thi duyet tiep
            }
            
            p = first;  }
             else {p = p->link; }    // Neu khong co ngay sinh bi trung thi duyet tiep
    }

    if (!DSCotrung) {
        cout << "Khong tim thay sinh vien cung ngay sinh." << endl;
    }
}


void InDanhSach(Node* first) {
    if (first == nullptr) {
        cout << "Danh sach trong!" << endl;
        return;
    }

    cout << "\n                DANH SACH SINH VIEN                     " << endl;
    cout << "   MSSV        Ho Ten      GT    Ngay Sinh  Lop  Khoa " << endl;
    cout << "------------------------------------------------------------" << endl;

    Node* p = first;
    while (p != nullptr) {  cout << p->data.maSV << " | " << p->data.hoTen << " - ";

    if (p->data.gioiTinh == 1) cout << "Nam - ";
    else cout << "Nu - ";
    cout << p->data.ngaySinh.ngay << "/" << p->data.ngaySinh.thang << "/"  << p->data.ngaySinh.nam << " - " << p->data.lop << " - " << p->data.khoa << endl;
        p = p->link;
    }
}

int main() {
    List ListSV;
    ListSV.first = nullptr; 
    ListSV.last = nullptr;
 
    ThemSV( ListSV, {"202414405", "Tran Hoang Hai", 1, {10, 1, 2006}, "HN", "DT05", "SEEE"});
    ThemSV( ListSV, {"202414406", "Nguyen Duc Duy", 1, {15, 2, 2006}, "HN", "DT05", "SEEE"});
    ThemSV( ListSV, {"202414401", "Nguyen Duc Kien", 1, {20, 3, 2006}, "HN", "DT05", "SEEE"});
    ThemSV( ListSV, {"202414413", "Ha Dang Quang", 1, {5, 4, 2006}, "HN", "DT05", "SEEE"});
    ThemSV( ListSV, {"202414203", "Van Thanh Dat", 1, {12, 5, 2006}, "HN", "DT05", "SEEE"});
    ThemSV( ListSV, {"202414073", "Nguyen Khanh Huyen", 0, {25, 6, 2006}, "HN", "DT05", "SEEE"});
    ThemSV( ListSV, {"202414074", "Le Khanh Linh", 0, {25, 6, 2006}, "HN", "DT05", "SEEE"});
    ThemSV( ListSV, {"202414063", "Nguyen Manh Thien", 1, {30, 7, 2006}, "HN", "DT05", "SEEE"});
    ThemSV( ListSV, {"202414058", "Tran Duc Manh", 1, {30, 7, 2006}, "HN", "DT05", "SEEE"});
    ThemSV( ListSV, {"202414365", "Nguyen Quoc Huy", 1, {30, 7, 2006}, "HN", "DT05", "SEEE"});
    ThemSV( ListSV, {"202414103", "Hoang Lam Que", 0, {18, 8, 2006}, "HN", "DT05", "SEEE"});

     InDanhSach( ListSV.first);

    cout << "\nCac Sinh vien co trung ngay sinh la:" << endl;
    TimXoaSV( ListSV.first);





    return 0;
}
