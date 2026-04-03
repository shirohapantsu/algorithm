#include <bits/stdc++.h>
using namespace std;

void dfs(int a,int b,int n,int &ans,int cnt,vector<int> &op,vector<int> &selected)
{
    if(a<1 || a>n) return;
    if(selected[a]!=-1 && cnt >= selected[a])
    {
        return;
    }
    if(a == b)
    {
        if(ans == -1) ans = cnt;
        ans = min(ans,cnt);
        return;
    }

    selected[a] = cnt;
    dfs(a+op[a-1],b,n,ans,cnt+1,op,selected);
    dfs(a-op[a-1],b,n,ans,cnt+1,op,selected);

}

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> op(n);
    vector<int> selected(n+1,-1);
    for(int i=0;i<n;i++)
    {
        cin >> op[i];
    }

    int ans = -1;
    dfs(a,b,n,ans,0,op,selected);
    cout << ans;
    return 0;
}

/*
DFS配合剪枝：

剪枝1：记录第一次搜索成功的次数，当搜索的次数超过时就立刻停止

剪枝2：记录在搜索中是否会到达同一楼层，如果第二次到达统一楼层立刻停止

剪枝3：使用1,2后仍然超时，则可以记录到达每一楼层时的搜索次数，如果在多次
搜索中到达该楼层的次数与之前的相比更多或相同，则说明本次搜索不是最优解，
立即停止；若某次搜索中到达某一楼层的次数低于之前的次数，则更新到达该楼层
时的最小搜索次数
*/