#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;cin>>n;
    vector<int> a(n);vector<int> b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i=0,j=0;
    int cnt = 0;
    while(j!=a.size() && i!=b.size())
    {
        
        if(b[i] >= a[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
            cnt++;
        }
    }

    cout << a.size()-cnt;

    return 0;
}

/*
简单的贪心
*/