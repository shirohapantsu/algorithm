#include <bits/stdc++.h>
using namespace std;
int t,m;
int times[110];
int values[110];
int dp[1010] = {0};

int main()
{
    cin>>t>>m;
    for(int i=1;i<=m;i++)
        cin >> times[i] >> values[i];

    for(int i=1;i<=m;i++)
    {
        for(int j=t;j>=times[i];j--)
        {
            dp[j] = max(dp[j],dp[j-times[i]]+values[i]);
        }
    }

    cout << dp[t];
    return 0;
}

/*
0-1背包dp
*/