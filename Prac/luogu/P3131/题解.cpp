#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n+1,0);
    vector<int> pos(7,-1);
    pos[0] = 0;
    
    int tmp,res=0;
    
    for(int i=1;i<=n;i++)
    {
        cin >> tmp;
        nums[i] = (nums[i-1] + tmp) % 7;

        if(pos[nums[i]] == -1)
            pos[nums[i]] = i;
        else res = max(res,i-pos[nums[i]]);        
    }
    cout << res;
    return 0;
}

/*
思路：这道题给的时间很短，数据量也很大肯定不能暴力枚举
注意题目本质是求区间和是7的倍数的最大区间，所以要使用前缀和进行数据预处理

但是这个题太傻逼了，只用前缀和还不够

所以需要用到同余定理：
两个整数a、b，如果他们同时除以一个自然数m，所得的余数相同，则称a、b对于模m同余
对于同一个除数，如果有两个整数同余，那么它们的差就一定能被这个除数整除

也就是说，对于前缀和数组nums，如果(nums[i] - nums[7]) % 7 == 0
那么 nums[i] % 7 ==nums[j] % 7

所以我们只需要求出前缀和数组每一项对于7的模，再用同一余数最后
出现的位置减去最早出现的位置就是该余数对应的最大区间

考察点：前缀和；数论：同余
*/