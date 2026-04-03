#include <bits/stdc++.h>
using namespace std;
string yizhong = "yizhong";
vector<int> dfsx = {-1,0,1,-1,1,-1,0,1};
vector<int> dfsy = {-1,-1,-1,0,0,1,1,1};

bool dfs(int flag,int d,vector<string> &s,int row,int col,int n,vector<string> &selected)
{
    if(d == 7) return true;
    if(row<0 || row>n-1 || col<0 || col>n-1) return false;
    
    if(s[row][col] == yizhong[d])
    {
        bool f = dfs(flag,d+1,s,row+dfsy[flag],col+dfsx[flag],n,selected);
        if(f)
        {
            selected[row][col] = s[row][col];
            return true;
        }
        else return false;
    }
    else return false;
}

int main()
{
    int n;cin>>n;
    vector<string> s(n);
    vector<string> selected(n, string(n, '*'));
    
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[i][j]=='y')
            {
                for(int flag=0;flag<8;flag++)
                {
                    dfs(flag,0,s,i,j,n,selected);
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << selected[i] << '\n';
    }
}

/*
dfs范式：洪水填充
*/