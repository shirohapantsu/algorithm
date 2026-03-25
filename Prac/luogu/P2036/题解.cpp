#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> s(100);
vector<int> b(100);
int res = 100000000;

void dfs(int i,int prot,int sum)
{
    if(i==n)
    {
        if(prot==1&&sum==0) return;
        else 
        {
            res = min(res,abs(sum-prot));
            return;
        }
    }

    dfs(i+1,prot,sum);
    dfs(i+1,prot*s[i],sum+b[i]);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin >> s[i] >> b[i];
    }
    dfs(0,1,0);
    cout << res;
    return 0;
}

/*
非常标准的DFS，这道题不需要回溯，对于每个选项都有 选/不选
两种情况，完全遍历实际上就构成了一棵选择二叉树

用遍历二叉树的思想对这种类型题目进行DFS即可
*/