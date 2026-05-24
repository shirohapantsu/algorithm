#include <bits/stdc++.h>
#define int long long 
using namespace std;

int a,b,c;
int mem[21][21][21] = {0};

int w(int a,int b,int c)
{
    if(a<=0 || b<=0 || c<=0)
        return mem[0][0][0] = 1;
    if(a>20 || b>20 || c>20)
    {
        a = b = c = 20;
        return mem[20][20][20] = w(20,20,20);
    }
    if(mem[a][b][c]) return mem[a][b][c];

    else if(a<b && b<c)
        return mem[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
    else return mem[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
}

signed main()
{
    while(true)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a==-1 && b==-1 && c==-1) break;

        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
    }
    return 0;
}

/*
简单的记忆化搜索
注意及时更新abc，防止数组越界
*/