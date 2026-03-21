#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,c;
    cin >> n >> c;

    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());

    int l = 0;
    int r = 0;
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        while(l<n && nums[l]<nums[i]+c)
            l++;
        while(r<n && nums[r]<=nums[i]+c)
            r++;

        ans += (r - l);
    }

    cout << ans;
    return 0;
}

/*
解法2：双指针法
对于A - B = C我们可以化为A = B + C
然后令原数组有序，得益于数组的有序性，我们就可以发现：对于每一个B，数组中
可能存在的A都在一个区间内，即 第一个比A小的数 < A < 第一个比A大的数；
因此我们可以枚举B，然后利用两个指针分别标记第一个小于A的数和第一个等于A的
数，两指针间的插值即当前的B对应的A的个数；每个B对应的A的数的加和就是题目要求
的数对的总数
*/