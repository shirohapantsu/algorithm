#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int tmp;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> tmp;
        a[i] = a[i-1] + tmp;
    }
    int m;
    cin >> m;
    int l,r;
    for(int i=0;i<m;i++)
    {
        cin >> l >> r;
        cout << a[r] - a[l-1] << '\n';
    }
    return 0;
}

/*
就是大数据量考察前缀和
*/