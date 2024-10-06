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
//quick sort kieu 2
// vector<int> quickSort(vector<int> arr) {
//     if (arr.size() <= 1) {
//         return arr; // Base case: If array is empty or has one element, it's already sorted.
//     }

//     int pivot = arr[arr.size() - 1]; // Choose the last element as the pivot
//     vector<int> left;  // Elements less than or equal to pivot
//     vector<int> right; // Elements greater than pivot

//     for (int i = 0; i < arr.size() - 1; i++) {
//         if (arr[i] <= pivot) {
//             left.push_back(arr[i]);
//         } else {
//             right.push_back(arr[i]);
//         }
//     }

//     // Recursively sort the left and right parts
//     left = quickSort(left);
//     right = quickSort(right);

//     // Concatenate the results
//     left.push_back(pivot); // Place pivot between the two partitions
//     left.insert(left.end(), right.begin(), right.end());

//     return left;
// }
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
