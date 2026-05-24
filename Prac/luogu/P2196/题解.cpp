#include <bits/stdc++.h>
using namespace std;

int n;
bool edge[21][21];
int value[21];
int dp[21];
int pre[21];

void print_path(int x)
{
    if(pre[x]!=0)
    {
        print_path(pre[x]);
    }
    cout << x << ' ';
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> value[i];
        dp[i] = value[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++) cin >> edge[i][j];
    }

    for(int j=2;j<=n;j++)
    {
        for(int i=1;i<j;i++)
        {
            if(edge[i][j])
            {
                if(dp[i]+value[j] > dp[j])
                {
                    dp[j] = dp[i] + value[j];
                    pre[j] = i;
                }   
            }
        }   
    }

    int* index = max_element(dp+1,dp+n+1);
    print_path(index - dp);

    cout << '\n';
    cout << *index;
    return 0;
}

/*
DAG的dp 和 dp路径的记录
*/