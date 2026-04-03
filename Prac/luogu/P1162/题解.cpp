#include <bits/stdc++.h>
using namespace std;

void dfs(int x,int y,vector<vector<int>> &nums,int n)
{
    if(x<0 || y<0 || x>n+1 ||  y>n+1 || nums[x][y] !=0) return;

    nums[x][y] = 3;
    dfs(x+1,y,nums,n);
    dfs(x-1,y,nums,n);
    dfs(x,y+1,nums,n);
    dfs(x,y-1,nums,n); 
}

int main()
{
    int n;cin>>n;
    vector<vector<int>> nums(n+2,vector<int>(n+2,0));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> nums[i][j];
        }
    }

    dfs(0,0,nums,n);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(nums[i][j]==0)nums[i][j] = 2;
            if(nums[i][j]==3)nums[i][j] = 0;
            cout << nums[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

/*
洪水dfs，但是这里用到了一个小技巧：
除去 1 和 1 外面的 0 就是题目要求的被1包围的0
在原数据周围再包裹一圈0 确保外界的0相连通
*/