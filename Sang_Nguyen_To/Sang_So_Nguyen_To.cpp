#include <iostream>
using namespace std;
int prime[10000001];

void sang()
{
    for(int i = 0; i < 10000000; i++)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1];
    for(int i = 2; i*i <= 10000000; i++)
    {
        if(prime[i] == 1)
        {
            for(int j = i*i; j <= 10000000; j+= i)
            {
                prime[j] = 0;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    sang();
    for(int i = 2; i <=n; i++)
    {
        if(prime[i]) cout << i << " ";
    }
}