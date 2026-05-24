#include <bits/stdc++.h>
using namespace std;
#define int long long 

int M,N;
int l,r=0,mid,ans;
int nums[100010];

bool check(int mid)
{
    int mid_M = 1;
    int tmp = nums[0];
    for(int i=1;i<N;i++)
    {
        tmp += nums[i];
        if(tmp > mid)
        {
            tmp = nums[i];
            mid_M++;
        }
    }
    return mid_M <= M;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        cin >> nums[i];
        r += nums[i];
    }

    l = *max_element(nums,nums+N);


    while(l <= r)
    {
        mid = l + (r - l) / 2;

        if(check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans;
    return 0;
}

/*
二分解决最大值最小化类型问题

问题模型：
1. 设x是最大段和 nums.max <= x <= nums.sum
2. x从小增大时，可以分成的合法段数M_x从大到小，形成了单调对应关系
3. 二分找出使 M_x <= M 时x的最小值
4. M_x 使用贪心求出
*/