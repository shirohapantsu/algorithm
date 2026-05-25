#include <bits/stdc++.h>
using namespace std;

int n;
int dp[10];
int ans;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string num;
        cin >> num;

        int head = num.front() - '0';
        int tail = num.back() - '0';

        dp[tail] = max(dp[tail],dp[head]+1);

        ans = max(ans,dp[tail]);
    }

    cout << n - ans;
    return 0;
}

/*
把“基于位置的 DP”转化为“基于特征/值域的 DP”
*/