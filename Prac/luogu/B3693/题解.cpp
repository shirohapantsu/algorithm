#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for(int r=0;r<t;r++)
    {
        int n,m,q;
        cin >> n >> m >> q;

        ll ans = 0;
        vector<vector<ll>> ps(n+1,vector<ll>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin >> ps[i][j];
                ps[i][j] = ps[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            }
        }
        
        ll res = 0;
        for(int k=0;k<q;k++)
        {
            int u,v,x,y;
            cin >> u >> v >> x >> y;
            ans = (ps[x][y] - ps[u-1][y] - ps[x][v-1] + ps[u-1][v-1]);
            res ^= ans;
        }
        
        cout << res << '\n';
    }
    return 0;
}

/*
简单的二维前缀和
*/