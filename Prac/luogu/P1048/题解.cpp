#include <bits/stdc++.h>
using namespace std;
int t,m;
int times[110];
int values[110];
vector<vector<int>> mems(110,vector<int>(1010,-1));

int dfs(int pos,int l_time)
{
    if(mems[pos][l_time] != -1) return mems[pos][l_time];
    else
    {
        if(pos == m + 1)
        {
            mems[pos][l_time] = 0;
            return mems[pos][l_time];
        }
        
        int state1,state2 = 0;
        state1 = dfs(pos+1,l_time);
        if(l_time >= times[pos])
            state2 = dfs(pos+1,l_time-times[pos]) + values[pos];
        mems[pos][l_time] = max(state1,state2);
        return mems[pos][l_time];
    }
}

int main()
{
    cin>>t>>m;
    for(int i=1;i<=m;i++)
        cin >> times[i] >> values[i];

    cout << dfs(0,t);

    return 0;
}

/*
记忆化搜索 
*/