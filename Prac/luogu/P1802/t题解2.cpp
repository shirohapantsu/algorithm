#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n,x,lose,win,use;
// int lose[1010];
// int win[1010];
// int use[1010];
int dp[1010];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> x;
    for(int i=1;i<=n;i++)
    {
        cin >> lose>> win >> use;

        for(int j=x;j>=0;j--)
        {
            if(j<use) dp[j] = dp[j] + lose;
            else dp[j] = max(dp[j]+lose,dp[j-use]+win);
        }
    }

    cout << 5 * dp[x];
    return 0;
}

/*
滚动数组优化
*/