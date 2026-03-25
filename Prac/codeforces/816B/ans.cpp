#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n,k,q;
    cin >> n >> k >> q;

    int l,r;
    vector<int> rec(200001,0);
    for(register int i=0;i<n;i++)
    {
        cin >> l >> r;
        rec[l]++;rec[r+1]--;
    }

    for(register int i=1;i<200001;i++)
    {
        rec[i] = rec[i-1] + rec[i];
        if(rec[i] < k) rec[i] = 0;
        else rec[i] = 1;
        rec[i] = rec[i-1] + rec[i];
    }

    int a,b;
    for(register int i=0;i<q;i++)
    {
        cin >> a >> b;
        cout << rec[b] - rec[a-1] << '\n';
    }
    return 0;
}

/*
这道题用到了前缀和和差分：
前缀和用来降低询问时的查询复杂度
差分用来降低统计温度推荐个数时的复杂度

统计温度推荐指数的差分 --> 前缀和还原为真正的温度推荐指数 --> 遍历判断温度推荐指数是否符合karen要求
--> 前缀和统计询问温度区间内的有效温度个数

*/