#include <bits/stdc++.h>
using namespace std;

void dfs(int n,int d,vector<int> &res,vector<bool> &ves)
{
    if(d >= n)
    {
        for(int i=0;i<n;i++)
        {
            cout << setw(5) << res[i];
        }
        cout << '\n';
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(!ves[i])
        {
            ves[i] = true;
            res[d] = i;
            dfs(n,d+1,res,ves);
            ves[i] = false;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> res(n);
    vector<bool> ves(n+1);
    
    dfs(n,0,res,ves);
    return 0;
}

/*
基于深度优先搜索的简单回溯
*/