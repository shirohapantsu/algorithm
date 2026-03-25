#include <bits/stdc++.h>
using namespace std;

void bfs(int n,int time_now,vector<int> &arrive_times,vector<int> &max_times,vector<int> &end_times,vector<bool> &selected,int res,bool &flag)
{
    if(res == n)
    {
        flag = true;
    }

    for(int i=0;i<n;i++)
    {
        int tmp = time_now;
        if(time_now < arrive_times[i]) time_now = arrive_times[i];
        if(time_now <= max_times[i] && !selected[i])
        {
            selected[i] = true;
            time_now += end_times[i];
            res++;
            bfs(n,time_now,arrive_times,max_times,end_times,selected,res,flag);
            time_now -= end_times[i];
            selected[i] = false;
            res--;
        }
        time_now = tmp;
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;cin>>n;
        vector<int> arrive_times(n);
        vector<int> max_times(n);
        vector<int> end_times(n);
        vector<bool> selected(n);
        bool flag = false;
        
        for(int j=0;j<n;j++)
        {
            cin >> arrive_times[j] >> max_times[j] >> end_times[j];
            max_times[j] = arrive_times[j] + max_times[j];
        }

        bfs(n,0,arrive_times,max_times,end_times,selected,0,flag);

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
回溯
*/