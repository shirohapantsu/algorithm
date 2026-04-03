#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;cin>>str;
    sort(str.begin(),str.end(),greater<char>());

    string ans;
    for(int i=0;i<str.size();i++)
    {
        if(str[i] != str[0])
            break;
        else ans += str[0];
    }
    cout<<ans;
    return 0;
}

/*
简单的贪心：注意到要求最大回文子序列，所以只要把字符串中所有最大的字符输出即可
*/