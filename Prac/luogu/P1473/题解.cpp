#include <bits/stdc++.h>
using namespace std;

char s[3] = {' ','+','-'};

bool isAns(string str)
{
    int num = 0;
    int tmp = 0;
    int sign = 1;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            tmp = tmp*10 + str[i] -'0';
        }
        if(str[i] == '+')
        {
            num += tmp*sign;
            tmp = 0;
            sign = 1;
        }
        if(str[i] == '-')
        {
            num += tmp*sign;
            tmp = 0;
            sign = -1;
        }
    }
    num += tmp*sign;
    if(num == 0) return true;
    else return false;
}

void dfs(string &str,int n,int d)
{
    if(d > 2*n-2)
    {
        if(isAns(str))
        {
            cout << str << endl;
            return;
        }
        return;
    }

    for(int i=0;i<3;i++)
    {
        str[d] = s[i];
        dfs(str,n,d+2);
    }
}

int main()
{
    int n;cin>>n;
    string str(2*n-1,' '); 
    for(int i=0;i<2*n-1;i+=2)
    {
        str[i] = i/2 + 1 + '0';
    }
    dfs(str,n,1);
    return 0;
}

/*
这道题的搜索部分不难，主要难在将字符串转换为运算的部分
这里的思路是：
利用tmp储存运算前的部分，利用sign和tmp在每一次运算前对前面的部分进行一次
结算，并在遇到运算时更新一次tmp和sign；直到遍历完成，在结束后最后结算一次
tmp和sign，得到最终的值
*/