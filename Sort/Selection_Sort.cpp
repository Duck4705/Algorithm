#include <iostream>
using namespace std;
void swap(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}
void Selection_Sort(int arr[], int n)
{
    for(int step = 0; step < n - 1; step++)
    {
        int min_idx = step;
        for(int i = step + 1; i < n; i++)
        {
            if(arr[i] < arr[min_idx])
            {
                min_idx = i;
            }
        }
        swap(arr[min_idx], arr[step]);
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
    Selection_Sort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}