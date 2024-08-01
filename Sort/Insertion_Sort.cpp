#include <iostream>
using namespace std;
void Insertion_Sort(int arr[], int n)
{
    for(int step = 1; step < n; step++)
    {
        int key = arr[step];
        int i = step - 1;
        while(key < arr[i] && i >= 0)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Insertion_Sort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}