#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
    int n,m;cin>>n>>m;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    sort(h.begin(),h.end());

    int l=0,r=h[n-1];
    int ans = 0;

    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        vector<int>::iterator mid_it = lower_bound(h.begin(),h.end(),mid);

        int sum = 0;
        for(auto it=mid_it;it!=h.end();it++) sum += *it - mid;

        
        if(sum >= m)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    } 
    cout << ans;
    return 0;
}

/*
我恨二分
*/