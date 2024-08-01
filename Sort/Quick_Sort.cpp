#include <iostream>
using namespace std;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int divide(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void Quick_Sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = divide(arr, low, high);
        Quick_Sort(arr, low, pi - 1);
        Quick_Sort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Quick_Sort(a, 0, n - 1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}