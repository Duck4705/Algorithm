#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int* c = a;
    a = b;
    b = c;
}

void heapify(int arr[], int n, int i) // Tao ra MAX_HEAP tai mot node
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    // Tao ra MAX_HEAP tren toan bo cay
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr,n,i);
    }

    for(int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        // heapify lai de dam bao node tai vi tri 0 la lon nhat
        heapify(arr,i,0);
    }
}

int main()
{
    int arr[10] = {6, 5, 2, 6, 1, 8, 0, -1, 6, 2};
    heap_sort(arr,10);
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}