#include <bits/stdc++.h>
using namespace std;

string river[2];
int ans = 0;

pair<int,int> find_next(int j)
{
    while(1)
    {
        j++;
        if(river[0][j]=='#') return {0,j};
        if(river[1][j]=='#') return {1,j};
    }
}

int main()
{
    cin >> river[0] >> river[1];
    int last_index = max((int)river[0].rfind('#'),(int)river[1].rfind('#'));
    
    for(int i=0;i<last_index;i++)
    {
        if(river[0][i]=='#' && river[1][i]=='.')
        {
            if(river[0][i+1]=='#') continue;
            else
            {
                river[0][i+1] = '#';
                ans++;  
            }
        }
        if(river[0][i]=='.' && river[1][i]=='#')
        {
            if(river[1][i+1]=='#') continue;
            else
            {
                river[1][i+1] = '#';
                ans++;
            }
        }
        if(river[0][i]=='#' && river[1][i]=='#')
        {
            pair<int,int> res = find_next(i);
            while(i+1 < res.second)
            {
                i++;
                ans++;
                river[res.first][i] = '#';
            }
        }
    }

    cout << ans;
    return 0;
}

/*
贪心解
*/