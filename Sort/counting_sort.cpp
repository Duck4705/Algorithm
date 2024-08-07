#include <iostream>
#include <vector>
using namespace std;

void Counting_Sort(vector<int>& a)
{
    int n = a.size();
    // Tìm giá trị lớn nhất và nhỏ nhất trong mảng
    int max = a[0], min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (max < a[i]) max = a[i];
        if (min > a[i]) min = a[i];
    }

    // Dải giá trị cần đếm (từ min đến max)
    int range = max - min + 1;
    vector<int> temp(range, 0); // Mảng đếm
    vector<int> output(n); // Mảng kết quả

    // Đếm số lần xuất hiện của mỗi phần tử
    for (int i = 0; i < n; i++)
    {
        temp[a[i] - min]++;
    }

    // Tính toán vị trí của các phần tử
    for (int i = 1; i < range; i++)
    {
        temp[i] += temp[i - 1];
    }

    // Xây dựng mảng output
    for (int i = n - 1; i >= 0; i--)
    {
        output[temp[a[i] - min] - 1] = a[i];
        temp[a[i] - min]--;
    }

    // Sao chép mảng output vào lại mảng a
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
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

    Counting_Sort(a);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
