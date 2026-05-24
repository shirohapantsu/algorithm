#include <bits/stdc++.h>
using namespace std;

int n,sum;
bool used[13];
int yanghui[12];
vector<int> nums;

void dfs(int total)
{   
    if(total > sum) return;
    
    if(total == sum && nums.size()==n)
    {
        for(int i=0;i<n;i++) cout << nums[i] << ' ';
        exit(0);
    }

    for(int i=1;i<=n;i++)
    {
        if(used[i]) continue;

        nums.push_back(i);
        used[i] = true;

        dfs(total+i*yanghui[nums.size()-1]);

        nums.pop_back();
        used[i] = false;
    }
}

int main()
{
    cin >> n >> sum;
    yanghui[0] = 1;
    for(int i=1;i<n;i++)
    {
        yanghui[i] = yanghui[i-1] * (n - i) / i;
    }

    dfs(0);
    return 0;
}

