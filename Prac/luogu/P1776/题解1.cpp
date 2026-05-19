#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n,W,v,w,m;
int weight[100010];
int value[100010];
int dp[40010] = {0};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> W;
    int index = 0;

    for(int i=1;i<=n;i++)
    {
        cin >> v >> w >> m;
        for(int k=1;k<=m;k*=2)
        {
            m -= k;
            index++;
            weight[index] = k * w;
            value[index] = k * v;
        }
        if(m > 0)
        {
            index++;
            weight[index] = w * m;
            value[index] = m * v;
        }
    }

    for(int i=1;i<=index;i++)
    {
        for(int j=W;j>=weight[i];j--)
        {
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }

    cout << dp[W];
    return 0;
}

/*
二进制拆分优化的多重背包dp问题
*/