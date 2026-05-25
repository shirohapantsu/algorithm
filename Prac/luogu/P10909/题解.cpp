#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100000010];
int dis[100000010];

bool check(int mid)
{
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(mid >= dis[i])
        {
            cnt++;
            continue;
        }
        else 
        {
            cnt += (dis[i] + mid - 1) / mid;
        }
    }

    return cnt <= m;
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        dis[i] = a[i] - a[i-1];
    }
    m = m + n + 1;

    int l = 1;
    int r = *max_element(dis,dis+n+1);
    int ans = 0;

    while(l <= r)
    {
        int mid = l + (r - l) / 2;

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
二二的分
*/