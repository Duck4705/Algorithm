#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    char s[1000];
    cin.getline(s,256);
    int n = strlen(s);

    while(s[0]==' '){
        for(int i=0;i<n;i++){
            s[i]=s[i+1];
        }
    }
    // xoa khoang trang cuoi chuoi
    while(n > 0 && s[n - 1] == ' '){
        s[n-1] ='\0';
        n--;
    }
    // Xóa khoảng trắng thừa giữa các từ
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            for (int j = i; s[j] != '\0'; ++j) {
                s[j] = s[j + 1];
            }
            n--;
            --i;
        }
    }
    cout << s << n;
}
