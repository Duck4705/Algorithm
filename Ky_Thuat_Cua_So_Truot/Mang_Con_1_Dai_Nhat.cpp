#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int max(int a, int b)
{
    if(a > b) return a;
    return b;
}
int find(vector<int> a, int k)
{
    int left = 0, curr = 0, ans = 0;
    for(int right = 0; right < a.size(); right++)
    {
        if(a[right] == 0)
        {
            curr++;
        }
        while (curr > k)
        {
            if(a[left] == 0) curr--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}
int main()
{
    string input;
    getline(cin, input);
    vector<int> a;
    stringstream s(input);
    int number;
    while(s >> number)
    {
        a.push_back(number);
    }
    int k;
    cin >> k;
    cout << find(a,k);
}