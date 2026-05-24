#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k,sum=0,avrge;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    vector<int> wood(n);

    for(int i=0;i<n;i++) 
    {
        cin >> wood[i];
        sum += wood[i];
    }
    sort(wood.begin(),wood.end(),greater<int>());

    if(sum < k)
    {
        cout << 0;
        return 0;
    }
    
    int left = 1;
    int right = sum / k;
    int mid,ans=0;

    while(left <= right)
    {
        int total = 0;
        mid = left + (right - left) / 2;

        for(int i=0;i<n;i++)
        {
            if(wood[i] < mid) break;
            total += wood[i] / mid;
        }
        if(total >= k) 
        {
            ans = mid;
            left = mid + 1;
        }
        else if(total < k) right = mid - 1;

    }

    cout << ans;
    return 0;
}

/*
二分
*/