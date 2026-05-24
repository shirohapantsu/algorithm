#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n,x,lose,win,use;
// int lose[1010];
// int win[1010];
// int use[1010];
int dp[1010][1010];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> x;
    for(int i=1;i<=n;i++)
    {
        cin >> lose>> win >> use;
        // dp[i][0] = dp[i-1][0] + lose[i];

        for(int j=0;j<=x;j++)
        {
            if(j<use)dp[i][j] = dp[i-1][j] + lose;
            else dp[i][j] = max(dp[i-1][j]+lose,dp[i-1][j-use]+win);
        }
    }

    cout << 5 * dp[n][x];
    return 0;
}

/*
类背包dp问题：这类问题的状态转移逻辑比基础背包DP多了一层“保底收益”

这里是二维解法
*/