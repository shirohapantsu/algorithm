#include <bits/stdc++.h>
#define int long long 
using namespace std;

int t,m;
int times[10000005]={0};
int values[10000005]={0};
int dp[10000005]={0};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> times[i] >> values[i];
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=times[i];j<=t;j++)
        {
            dp[j] = max(dp[j],dp[j-times[i]]+values[i]);
        }
    }
    cout << dp[t];
    return 0;
}

/*
完全背包问题典例
*/