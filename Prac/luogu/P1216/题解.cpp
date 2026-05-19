#include <bits/stdc++.h>
using namespace std;
int r;
int dp[1010][1010] = {0};

int main()
{
    cin >> r;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin >> dp[i][j];
        }
    }

    for(int i=r-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j] = max(dp[i+1][j]+dp[i][j],dp[i+1][j+1]+dp[i][j]);
        }
    }

    cout << dp[1][1];
    return 0;
}

/*
简单的dp
*/