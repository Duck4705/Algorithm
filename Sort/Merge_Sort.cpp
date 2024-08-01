#include <iostream>
using namespace std;

void Merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int A1[n1], A2[n2];

    for (int i = 0; i < n1; i++) {
        A1[i] = A[p + i];
    }
    for (int i = 0; i < n2; i++) {
        A2[i] = A[q + 1 + i];
    }

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (A1[i] <= A2[j]) {
            A[k] = A1[i];
            i++;
        } else {
            A[k] = A2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = A1[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = A2[j];
        j++;
        k++;
    }
}

void Merge_Sort(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        Merge_Sort(A, p, q);
        Merge_Sort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Merge_Sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}