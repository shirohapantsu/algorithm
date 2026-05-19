#include <bits/stdc++.h>
using namespace std;

int weight[6] = {1,2,3,5,10,20};
int cnt[6];
bool dp[1010] = {false};

int main()
{
    dp[0] = true;
    for(int i=0;i<6;i++) cin >> cnt[i];
    for(int i=0;i<6;i++)
    {
        for(int j=1000;j>=weight[i];j--)
        {
            for(int k=1;k*weight[i]<=j && k<=cnt[i];k++)
                dp[j] = dp[j] || dp[j-k*weight[i]];
        }
    }

    int ans = 0;
    for(int i=1;i<=1000;i++) if(dp[i]) ans++;
    cout << "Total=" << ans;
    return 0;
}

/*
1.多重背包问题
2.动态规划的可行性判定类型问题
*/