#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;

    vector<int> nums(n+1,0);
    vector<int> mods(k,0);
    mods[0] = 1;
    
    int tmp;
    for (int i=1;i<=n;i++)
    {
        cin >> tmp;
        nums[i] = (nums[i-1] + tmp) % k;

        mods[nums[i]]++;
    }

    long long res = 0;
    for(int i=0;i<k;i++)
    {
        long long x = mods[i] - 1;
        res += x*(x+1)/2;
    }
    cout << res;
    return 0;
}

/*
同理与P3131 就是前缀和和同余的问题

处理这种类型题一定要小心整数溢出，可以用
#define int long long 来偷懒==
*/