#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
    int n,d;cin>>n>>d;
    vector<int> v(n);
    vector<pair<int,int>> a;
    v[0] = 0;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        v[i] = v[i-1] + v[i];
    }
    int tmp,min;
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        if(tmp < min || i==0)
        {
            min = tmp;
            a.push_back(pair<int,int>(i,tmp));
        }
    }

    int ans = 0;
    int mod_oil = 0;
    int vol = 0;
    int start_stat = 0;

    if(a.size() != 1)
        for(int i=1;i<a.size();i++)
        {
            vol = (v[a[i].first] - v[start_stat] + d - 1 - mod_oil) / d;
            mod_oil = vol * d - (v[a[i].first] - v[start_stat] - mod_oil);
            ans += vol * a[i-1].second;
            start_stat = a[i].first;
        }
    vol = (v[n-1] - v[start_stat] + d - 1 - mod_oil) / d;
    ans += vol * a[a.size()-1].second;

    cout << ans;
    return 0;
    
}

/*
贪心+模拟
*/