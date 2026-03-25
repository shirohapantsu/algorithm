#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> res;
vector<int> x(25);
int n,k;

vector<int> primes;
vector<bool> numbers;

void dfs(int d,int num,int sum)
{
    if(num == k)
    {
        res.push_back(sum);
        return;
    }
    if(d == n) return;
    
    dfs(d+1,num+1,sum+x[d]);
    dfs(d+1,num,sum);
}

void isPrime(int m)
{
    numbers.assign(m+1,false);
    for(int i=2;i<=m;i++)
    {
        if(!numbers[i])
        {
            primes.push_back(i);
            for(int j=i*i;j<=m;j+=i)
            {
                numbers[j] = true;
            }
        }
    }
}

signed main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> x[i];
    }
    dfs(0,0,0);
    int max_val = *max_element(res.begin(),res.end());
    isPrime(max_val);

    int count = 0;
    for(auto it=res.begin();it!=res.end();++it)
    {
        if(binary_search(primes.begin(),primes.end(),*it))
            count++;
    }
    cout << count;
    return 0;
}

/*
DFS+素数筛
*/