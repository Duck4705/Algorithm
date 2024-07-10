#include<bits/stdc++.h>
#include <sstream>
using namespace std;
bool cmp(int a,int b){
    return abs(a)<abs(b);
}
int main(){
    string s;
    getline(cin,s);
    vector<int> nums;
    stringstream ss(s);
    int number;
    while(ss>>number){
        nums.push_back(number);
    }
    sort(nums.begin(),nums.end(),cmp);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]*nums[i];
        if(i!=nums.size()-1) cout<<" ";
    }
    return 0;
}