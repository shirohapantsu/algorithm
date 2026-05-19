#include <bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;

int dx[8] = {-2,-1,1,2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

bool check(vector<vector<int>> &visited,int n,int m,int x,int y)
{
    if(x<0 || x>n-1 || y<0 || y>m-1) return false;
    else if(visited[x][y]!=-1) return false;
    else return true;
}

void bfs(vector<vector<int>> &visited,int n,int m,int x,int y)
{
    queue<PII> q;
    q.push({x,y});

    while(!q.empty())
    {
        PII node = q.front();
        q.pop();

        for(int i=0;i<8;i++)
        {
            int node_x = node.first - 1 + dx[i];
            int node_y = node.second - 1 + dy[i];
            
            if(check(visited,n,m,node_x,node_y))
            {
                q.push({node_x+1,node_y+1});
                visited[node_x][node_y] = visited[node.first-1][node.second-1] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    
    int n,m,x,y;
    cin>>n>>m>>x>>y;

    vector<vector<int>> visited(n,vector<int>(m,-1));
    visited[x-1][y-1] = 0;
    bfs(visited,n,m,x,y);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/*
典型的bfs题目
注意在bfs类型题目中一定要对大参数按引用传参，否则调用函数时按值传参的拷贝
会占用大量时间，经常会导致超时
*/