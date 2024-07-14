# Danh sách liên kết  
***
1. Tạo danh sách liên kết  
Danh sách liên kết đơn:  
```cpp
#include <iostream>
using namespace std;

struct LinkedListNode
{
    int value;
    LinkedListNode *next;
    LinkedListNode(int value) : value(value), next(nullptr) {}
};
int main()
{
    LinkedListNode* one = new LinkedListNode(100);
    LinkedListNode* two = new LinkedListNode(200);
    LinkedListNode* three = new LinkedListNode(300);

    one->next = two;
    two->next = three;

    LinkedListNode* head = one;

    cout << head->value << endl; // 100
    cout << head->next->value << endl; // 200
    cout << head->next->next->value << endl; // 300
}
```
So sánh mảng và danh sách liên kết:  
![So_Sanh](So_Sanh.png)  

