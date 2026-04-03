#include <bits/stdc++.h>
using namespace std;

vector<int> opx = {-1,0,0,1};
vector<int> opy = {0,-1,1,0};
int ans = 10;

bool check(vector<vector<int>> lights)
{
    int sum = 0;
    for(int i=0;i<9;i++)
    {
        sum += lights[i/3][i%3];
    }
    if(sum == 9) return true;
    else return false;
}

void dfs(vector<vector<int>> &lights,int i,int flag,int count)
{
    if(check(lights))
    {
        ans = min(ans,count);
        return;
    }
    if(i>8) return;
    if(count>=ans)return;
    
    if(flag ==1)
    {
        lights[i/3][i%3] = !lights[i/3][i%3];
        for(int j=0;j<4;j++)
        {
            if(i%3+opx[j]<0 || i%3+opx[j]>2 || i/3+opy[j]<0 || i/3+opy[j]>2) continue;
            else lights[i/3+opy[j]][i%3+opx[j]] = !lights[i/3+opy[j]][i%3+opx[j]];
        }

        dfs(lights,i+1,1,count+1);
        dfs(lights,i+1,0,count);

        lights[i/3][i%3] = !lights[i/3][i%3];
        for(int j=0;j<4;j++)
        {
            if(i%3+opx[j]<0 || i%3+opx[j]>2 || i/3+opy[j]<0 || i/3+opy[j]>2) continue;
            else lights[i/3+opy[j]][i%3+opx[j]] = !lights[i/3+opy[j]][i%3+opx[j]];
        }
    }

    if(flag == 0)
    {
        dfs(lights,i+1,1,count+1);
        dfs(lights,i+1,0,count);
    }
}

int main()
{
    vector<vector<int>> lights(3,vector<int>(3,0));
    for(int i=0;i<9;i++)
    {
        cin >> lights[i/3][i%3];
    }
    dfs(lights,-1,0,0);
    cout << ans;
    return 0;
}

/*
要点在于理解对于每个灯都只有操作一次和不操作两种状态，两次操作无论顺序如何
都相当于没有操作，之后进行简单的DFS即可
*/