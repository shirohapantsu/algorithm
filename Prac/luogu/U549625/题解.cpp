#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> a(n+1,0);
    vector<int> a_max(n+1,0);
    
    for(register int i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i] = a[i-1] + a[i];
    }

    int min = a[0];
    a_max[n] = a[n];
    for(register int i=n-1;i>0;i--)
    {
        a_max[i] = max(a[i],a_max[i+1]);
    }
    for(register int i=1;i<=n;i++)
    {
        if(a[i-1] < min) min = a[i-1];
        cout << a_max[i] - min << ' ';
    }
    return 0;
}

/*
依旧求区间和公式化前缀和，这道题的难点在于如何处理包含某一项的最大区间和

常规暴力循环套俩循环时间复杂度 O(2n^2) 肯定不行，即使优化掉左侧最小值
的循环也有 O(n^2) 所以依旧空间换时间，开辟一个数组用一次循环就维护每个
元素的有右侧最大值

*/