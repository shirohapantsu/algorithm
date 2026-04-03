#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;cin>>n;
    vector<int> a(n,0);

    int maxEndingnow;
    int maxSoFar;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(i==0)
        {
            maxEndingnow = a[0];
            maxSoFar = a[0];
        }
        else
        {
            maxEndingnow = max(a[i],maxEndingnow+a[i]);
            maxSoFar = max(maxSoFar, maxEndingnow);
        }
    }

    cout << maxSoFar;
    return 0;
}

/*
kanade算法维护最大区间和
*/