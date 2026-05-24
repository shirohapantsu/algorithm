#include <bits/stdc++.h>
using namespace std;

int n;
int num[1000010];
int dp[1000010];
int ans;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        dp[i] = 1;
        cin >> num[i];
        for(int j=0;j<i;j++)
        {
            if(num[i] > num[j])
                dp[i] = max(dp[i],dp[j]+1);
        }
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;  
}