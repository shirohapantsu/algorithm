#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n,x;
    cin >> n >> x;

    vector<int> nums(n+1);
    int minEndinghere = 0,minEndingsoFar = 0;
    int sum = 0;
    for(register int i=1;i<=n;i++)
    {
        cin >> nums[i];
        nums[i] -= x;
        minEndinghere = min(nums[i],nums[i]+minEndinghere);
        minEndingsoFar = min(minEndinghere,minEndingsoFar);
        sum += nums[i];
    }
    minEndingsoFar = min((int)0,minEndingsoFar);
    cout << sum - minEndingsoFar + n*x;
    return 0;
}

/*
这个问题可以转化为求 nums[i] - x 后的数组的最小子数组的问题
nums[i]-x 反映了 原值 相较于 用x替换后的值 的变化情况
故找出最小子区间 就是要被替换的区间

寻找最大/最小自区间用到了 kanade算法
*/