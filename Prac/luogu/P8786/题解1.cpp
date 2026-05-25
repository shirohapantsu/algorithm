#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,m;
int dp[105][105][105];

signed main()
{
    cin >> n >> m;

    dp[1][0][1] = 1;
    dp[2][0][0] = 1;

    int k = 1;
    for(int i=0;i<=5;i++)
    {
        k*=2;
        dp[0][i][k] = 1;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<=m+2;k++)
            {
                if(k%2) dp[i][j][k] = dp[i-1][j][k+1] % 1000000007;
                else dp[i][j][k] = dp[i][j-1][k/2] + dp[i-1][j][k+1] % 1000000007;
            }
        }
    }

    cout << dp[m-1][n][1];
    return 0;
}

