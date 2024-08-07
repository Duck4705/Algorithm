#include <iostream>
#include <vector>
#include <algorithm> // for max_element and min_element

using namespace std;

// Modified Counting Sort to sort based on digit represented by exp
void Counting_Sort(vector<int>& a, int exp, int minValue)
{
    int n = a.size();
    vector<int> output(n); // Output array
    int i, count[19] = {0};

    // Store count of occurrences of digits (0-9) in count[]
    for (i = 0; i < n; i++)
        count[((a[i] - minValue) / exp) % 10 + 9]++;

    // Change count[i] so that it contains the actual position of this digit in output[]
    for (i = 1; i < 19; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) // Đảm bảo ổn định khi sắp xếp
    {
        output[count[((a[i] - minValue) / exp) % 10 + 9] - 1] = a[i];
        count[((a[i] - minValue) / exp) % 10 + 9]--;
    }

    // Copy the output array to a[], so that a[] now contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        a[i] = output[i];
}

// The main function to sort an array using Radix Sort
void Radix_Sort(vector<int>& a)
{
    // Find the maximum and minimum numbers to know the range of digits
    int maxValue = *max_element(a.begin(), a.end());
    int minValue = *min_element(a.begin(), a.end());

    // Do counting sort for every digit. Note that instead of passing digit number,
    // exp is passed. exp is 10^i where i is the current digit number
    for (int exp = 1; (maxValue - minValue) / exp > 0; exp *= 10)
        Counting_Sort(a, exp, minValue);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Radix_Sort(a);
    if(n != 0)
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

    return 0;
}
