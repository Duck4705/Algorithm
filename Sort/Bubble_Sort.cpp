#include <iostream>
using namespace std;
void Bubble_Sort(int arr[], int n)
{
    for(int step = 0; step < n - 1; step++)
    {
        bool swapped = false;
        for(int i = 0; i < n - step - 1; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = true;
            }
        }
        if(swapped != true) break;
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
    Bubble_Sort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}