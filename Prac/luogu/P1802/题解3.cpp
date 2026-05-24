#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n, x;
int dp[1010]; 

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> x;
    
    int base_exp = 0; // 记录保底的经验总和
    
    for(int i = 1; i <= n; i++)
    {
        int lose, win, use;
        cin >> lose >> win >> use;
        
        // 1. 无论如何，先把失败的保底经验塞进腰包
        base_exp += lose;
        
        // 2. 计算如果打赢，相比于打输能“多赚”多少经验
        int net_profit = win - lose; 
        
        // 3. 套用最基础的 0-1 背包模板
        // 注意：现在的循环终点不再是 0，而是 use 了！
        // 因为如果药水不够 (j < use)，额外收益就是 0，不需要做任何更新。
        for(int j = x; j >= use; j--) 
        {
            dp[j] = max(dp[j], dp[j - use] + net_profit);
        }
    }

    // 最终总经验 = (保底经验 + 药水换来的最大净利润)
    // 别忘了题目要求的乘以 5
    cout << 5 * (base_exp + dp[x]);
    return 0;
}

/*
利用基准值转换转换为标准0-1背包dp
*/