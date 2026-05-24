#include <bits/stdc++.h>
using namespace std;

int n;
string words[20];
int mem[20];
int length = 1;
int res = 0;

int check(string a,string b)
{
    int size = min(a.size(),b.size());
    for(int i=1;i<=size;i++)
    {
        bool flag = true;
        for(int j=0;j<i;j++)
        {
            if(a[a.size()-i+j] != b[j]) 
            {
                flag = false;
                break;
            }
        }
        if(flag) return i;
    }
    return 0;
}

void dfs(string tmp)
{
    res = max(res,length);
    for(int i=0;i<n;i++)
    {
        if(mem[i] == 2) continue;
        
        int coincide = check(tmp,words[i]);
        if(coincide > 0)
        {
            mem[i]++;
            length = length + words[i].size() - coincide;
            dfs(words[i]);
            mem[i]--;
            length = length + coincide - words[i].size();
        }
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> words[i];
    string a;
    cin >> a;

    dfs(a);
    cout << res;
    return 0;
}

/*
dfs
*/