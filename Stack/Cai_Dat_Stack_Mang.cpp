/* C++ program to implement basic stack
operations */
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack {
    int top;

public:
    int a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

// Driver program to test above functions
int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";

    //print top element of stack after popping
    cout << "Top element is : " << s.peek() << endl;

    //print all elements in stack :
    cout <<"Elements present in stack : ";
    while(!s.isEmpty())
    {
        // print top element in stack
        cout << s.peek() <<" ";
        // remove top element in stack
        s.pop();
    }

    return 0;
}

// Cài đặt bằng List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pNext;
    Node(int x) : data(x), pNext(nullptr) {}
};

struct ListNode {
    Node* pHead;
    Node* pTail;
};

// Khởi tạo danh sách liên kết
void CreateList(ListNode& l) {
    l.pHead = nullptr;
    l.pTail = nullptr;
}

// Thêm phần tử vào đầu danh sách
void AddHead(ListNode& l, Node* p) {
    if (l.pHead == nullptr) {
        l.pHead = p;
        l.pTail = l.pHead;
        return;
    }
    p->pNext = l.pHead;
    l.pHead = p;
}

// Xóa phần tử đầu danh sách
void DeleteHead(ListNode& l) {
    if (l.pHead == nullptr) return;
    Node* p = l.pHead;
    if (l.pHead == l.pTail) {
        l.pHead = l.pTail = nullptr;
    } else {
        l.pHead = l.pHead->pNext;
    }
    delete p;
}

// Lấy giá trị đầu danh sách
int Top(ListNode& l) {
    if (l.pHead == nullptr) throw runtime_error("Stack is empty.");
    return l.pHead->data;
}

// Kiểm tra danh sách có rỗng không
bool IsEmpty(ListNode& l) {
    return l.pHead == nullptr;
}

// Lớp Stack sử dụng danh sách liên kết
class Stack {
private:
    ListNode l; // Sử dụng danh sách liên kết làm ngăn xếp
public:
    Stack() {
        CreateList(l); // Khởi tạo danh sách rỗng
    }

    void push(int x) {
        AddHead(l, new Node(x)); // Thêm phần tử vào đầu danh sách
    }

    void pop() {
        if (IsEmpty(l)) {
            cout << "Stack underflow, cannot pop." << endl;
            return;
        }
        DeleteHead(l); // Xóa phần tử đầu danh sách
    }

    int top() {
        return Top(l); // Trả về giá trị đầu danh sách
    }

    bool isEmpty() {
        return IsEmpty(l); // Kiểm tra danh sách rỗng
    }

    void printStack() {
        Node* p = l.pHead;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->pNext;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    // Kiểm tra thêm vào stack
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Stack sau khi push: ";
    s.printStack(); // Kỳ vọng: 30 20 10

    // Kiểm tra lấy giá trị đỉnh stack
    cout << "Phan tu top cua stack: " << s.top() << endl; // Kỳ vọng: 30

    // Kiểm tra xóa phần tử khỏi stack
    s.pop();
    cout << "Stack sau khi pop: ";
    s.printStack(); // Kỳ vọng: 20 10

    // Kiểm tra stack rỗng
    cout << "Stack co rong khong? " << (s.isEmpty() ? "Co" : "Khong") << endl; // Kỳ vọng: Không

    // Xóa toàn bộ stack
    s.pop();
    s.pop();
    cout << "Stack co rong khong? " << (s.isEmpty() ? "Co" : "Khong") << endl; // Kỳ vọng: Có

    return 0;
}
