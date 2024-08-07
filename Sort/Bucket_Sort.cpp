#include <iostream>
#include <vector>
using namespace std;

void Insertion_Sort(vector<double>& arr, int n)
{
    for(int step = 1; step < n; step++)
    {
        double key = arr[step]; // Use double for key
        int i = step - 1;
        while(i >= 0 && key < arr[i]) // Check i before accessing arr[i]
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

void Bucket_Sort(vector<double>& arr, int n)
{
    if (n <= 0)
        return;
    int min_val = arr[0];
    int max_val = arr[0];
    // Find maximum value to normalize the values into buckets
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max_val) max_val = arr[i];
        if(arr[i] < min_val) min_val = arr[i];
    }

    // Create buckets
    vector<vector<double>> temp(n);

    // Normalize values to fit into buckets
    for (int i = 0; i < n; i++)
    {
        int bi = n * (arr[i] - min_val) / (max_val - min_val + 1); // Ensure bi is within valid range
        temp[bi].push_back(arr[i]);
    }

    // Sort each bucket and concatenate results
    for (int i = 0; i < n; i++)
    {
        Insertion_Sort(temp[i], temp[i].size());
    }
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < temp[i].size(); j++)
        {
            arr[index++] = temp[i][j];
        }
    }
}

int main()
{
    vector<double> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double x; // Use double to handle both integers and floating-point numbers
        cin >> x;
        arr.push_back(x);
    }
    Bucket_Sort(arr, n);
    for (auto x : arr)
    {
        cout << x << " ";
    }

    return 0;
}