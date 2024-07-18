#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
struct node
{
    int value;
    node* next;
};
node* createNode(int x)
{
    node* temp = new node;
    temp->value = x;
    temp->next = NULL;
    return temp;
}
node* addNode(node* head, int x)
{
    node* temp = createNode(x);
    head->next = temp;
    return temp;
}
node* swapNode(node* head, int left, int right)
{
    // Nếu danh sách trống hoặc chỉ có một phần tử hoặc left bằng right thì không cần đảo ngược
    if (head == nullptr || head->next == nullptr || left == right) return head;

    // Tạo một node dummy để dễ dàng thao tác
    node* dummy = new node();
    dummy->next = head;
    node* pre = dummy;

    // Di chuyển con trỏ pre đến vị trí trước left
    for (int i = 1; i < left; i++) {
        pre = pre->next;
    }

    // Bắt đầu đảo ngược từ vị trí left đến right
    node* current = pre->next;
    node* next = nullptr;

    for (int i = 0; i < right - left; i++) {
        next = current->next;
        current->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }

    // Trả về đầu danh sách mới đã được đảo ngược
    head = dummy->next;
    delete dummy;
    return head;

}
void print(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
int main()
{
    string s;
    getline(cin,s);
    stringstream str(s);
    int x;
    vector<int> a;
    while(str >> x)
    {
        a.push_back(x);
    }
    int left, right;
    cin >> left >> right;
    node* head = createNode(a[0]);
    node* temp = head;
    for(int i = 1; i < a.size(); i++)
    {
        temp = addNode(temp, a[i]);
    }
    head = swapNode(head, left, right);
    print(head);
}