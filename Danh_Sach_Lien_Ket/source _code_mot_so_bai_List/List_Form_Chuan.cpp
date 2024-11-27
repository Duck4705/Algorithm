#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* pNext;
    Node(int x) : data(x), pNext(nullptr) {}
};

struct ListNode
{
    Node* pHead;
    Node* pTail;
};

void CreateList(ListNode& l)
{
    l.pHead = nullptr;
    l.pTail = nullptr;
}

Node* CreateNode(int x)
{
    Node* p = new Node(x);
    return p;
}

void PrintList(ListNode& l)
{
    Node* p = l.pHead;
    while(p != nullptr)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
}
Node* SearchNode(ListNode& l, int x)
{
    Node* p = l.pHead;
    while(p != nullptr && p->data != x)
    {
        p = p->pNext;
    }
    return p;
}
void AddHead(ListNode& l, Node* p)
{
    if(l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = l.pHead;
        return;
    }
    p->pNext = l.pHead;
    l.pHead = p;
}
void AddTail(ListNode& l, Node* p)
{
    if(l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = l.pHead;
        return;
    }
    l.pTail->pNext = p;
    l.pTail = l.pTail->pNext;
}
void InsertAfterQ(ListNode& l, Node* p, Node* q)
{
    if(q != nullptr)
    {
        p->pNext = q->pNext;
        q->pNext = p;
        if(l.pTail == q) l.pTail = p;
        return;
    }
    AddHead(l,q);
}
// Phải cô lập phần tử cần hủy trước khi hủy
// Các vị trí có thể hủy:
// Hủy phần tử đứng đầu DS
// Hủy phần từ đứng cuối DS
// Hủy phần tử có khóa bằng x
// Hủy phần tử đứng sau q trong DS
void DeleteHead(ListNode& l)
{
    if(l.pHead == nullptr) return;
    Node* p = l.pHead;
    if(l.pHead == l.pTail)
    {
        l.pHead = l.pTail = nullptr;
    } else l.pHead = l.pHead->pNext;
    delete p;
}
void DeleteAfterQ(ListNode& l, Node* q)
{
    if(q == nullptr || q->pNext == nullptr) return;
    Node* p = q->pNext;
    if(p == l.pTail) l.pTail = q;
    q->pNext = p->pNext;
    delete p;
}
void RemoveX(ListNode& l, int x)
{
    // Trường hợp danh sách rỗng
    if (l.pHead == nullptr) return;

    // Xóa nút đầu nếu chứa giá trị x
    if (l.pHead->data == x)
    {
        Node* temp = l.pHead; // Lưu nút đầu để xóa
        l.pHead = l.pHead->pNext; // Cập nhật l.pHead

        // Nếu nút đầu cũng là nút cuối, cập nhật l.pTail
        if (temp == l.pTail)
        {
            l.pTail = nullptr;
        }

        delete temp; // Xóa nút đầu
        return;
    }

    // Tìm nút chứa giá trị x, đảm bảo q->pNext != nullptr
    Node* q = l.pHead;
    while (q->pNext != nullptr && q->pNext->data != x)
    {
        q = q->pNext;
    }

    // Nếu không tìm thấy giá trị x, thoát
    if (q->pNext == nullptr) return;

    // Xóa nút chứa giá trị x
    Node* p = q->pNext;
    q->pNext = p->pNext;

    // Nếu xóa nút cuối, cập nhật l.pTail
    if (p == l.pTail)
    {
        l.pTail = q;
    }

    delete p; // Xóa nút
}
void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void SelectionSort(ListNode& l)
{
    Node *p, *q, *min;
    p = l.pHead;

    while (p != nullptr)
    {
        min = p; // Giả sử phần tử hiện tại là nhỏ nhất
        q = p->pNext;

        // Tìm phần tử nhỏ nhất từ p->pNext đến cuối danh sách
        while (q != nullptr)
        {
            if (q->data < min->data) // So sánh với min->data thay vì p->data
            {
                min = q; // Cập nhật con trỏ min
            }
            q = q->pNext;
        }

        // Hoán đổi giá trị của p và min
        swap(min->data, p->data);
        p = p->pNext; // Tiến đến nút tiếp theo
    }
}

int main() {
    ListNode l;
    CreateList(l);

    // Kiểm tra thêm vào đầu danh sách
    AddHead(l, CreateNode(5));
    AddHead(l, CreateNode(3));
    AddHead(l, CreateNode(1));
    cout << "Danh sach sau khi them vao dau: ";
    PrintList(l); // Kỳ vọng: 1 3 5
    cout << endl;

    // Kiểm tra thêm vào cuối danh sách
    AddTail(l, CreateNode(7));
    AddTail(l, CreateNode(9));
    cout << "Danh sach sau khi them vao cuoi: ";
    PrintList(l); // Kỳ vọng: 1 3 5 7 9
    cout << endl;

    // Kiểm tra tìm kiếm
    Node* searchResult = SearchNode(l, 5);
    if (searchResult != nullptr)
        cout << "Tim thay gia tri " << searchResult->data << " trong danh sach." << endl;
    else
        cout << "Khong tim thay gia tri 5 trong danh sach." << endl;

    // Kiểm tra chèn sau phần tử
    Node* q = SearchNode(l, 5);
    if (q != nullptr) {
        InsertAfterQ(l, CreateNode(6), q);
        cout << "Danh sach sau khi chen 6 sau 5: ";
        PrintList(l); // Kỳ vọng: 1 3 5 6 7 9
        cout << endl;
    }

    // Kiểm tra xóa đầu danh sách
    DeleteHead(l);
    cout << "Danh sach sau khi xoa dau: ";
    PrintList(l); // Kỳ vọng: 3 5 6 7 9
    cout << endl;

    // Kiểm tra xóa sau phần tử
    q = SearchNode(l, 5);
    if (q != nullptr) {
        DeleteAfterQ(l, q);
        cout << "Danh sach sau khi xoa sau 5: ";
        PrintList(l); // Kỳ vọng: 3 5 7 9
        cout << endl;
    }

    // Kiểm tra xóa phần tử có giá trị cụ thể
    RemoveX(l, 7);
    cout << "Danh sach sau khi xoa gia tri 7: ";
    PrintList(l); // Kỳ vọng: 3 5 9
    cout << endl;

    // Kiểm tra sắp xếp danh sách
    AddTail(l, CreateNode(2));
    AddTail(l, CreateNode(8));
    cout << "Danh sach truoc khi sap xep: ";
    PrintList(l); // Kỳ vọng: 3 5 9 2 8
    cout << endl;

    SelectionSort(l);
    cout << "Danh sach sau khi sap xep: ";
    PrintList(l); // Kỳ vọng: 2 3 5 8 9
    cout << endl;

    return 0;
}
