#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,c;
    cin >> n >> c;

    map<int,int> cnt;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        cnt[nums[i]]++;
    }

    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += cnt[nums[i] + c];
    }
    
    cout << ans;
    return 0;
}

/*
解法1：使用map容器记录每个数字出现的次数，最后枚举B，
看有几个与之对应的A，做加和即可

map容器是基于红黑树的有序键值对结构，提供对书时间的操作

要注意，对于不存在的键的索引访问，map会自动为其创建一个
值为0的值，这会导致在原map中添加进污染数据；所以在查找不
确定键值时应该使用.find(key)方法（返回迭代器）或.count(key)
方法（返回键为key的元素的个数）

*/