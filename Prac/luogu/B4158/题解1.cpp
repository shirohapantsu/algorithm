#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> primes;
vector<bool> numbers(10000000,false);
vector<string> primes_s;


void isPrime()
{
    for(int i=2;i<=9999999;i++)
    {
        if(!numbers[i])
        {
            primes.push_back(i);
            for(int j=i*i;j<=9999999;j+=i)
                numbers[j] = true;
        }
    }

    for(auto it=primes.begin();it!=primes.end();it++)
    {
        primes_s.push_back(to_string(*it));
    }
    
}

bool check(string a,string b)
{
    if(a.size() != b.size()) return false;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i] && a[i]!='*') return false;
    }
    return true;
}

signed main()
{
    isPrime();
    int t;cin>>t;

    string str;
    for(int i=0;i<t;i++)
    {
        cin >> str;
        int flag = 0;
        for(int i=0;i<primes_s.size();i++)
        {
            if(check(str,primes_s[i]))
            {
                flag = 1;
                cout << primes_s[i] <<endl;
                break;
            }
        }
        if(flag == 0) cout << -1 <<endl;
    }
    return 0;
}

/*
极其暴力的把10^8以内的所有素数列举出来，依次比对
*/