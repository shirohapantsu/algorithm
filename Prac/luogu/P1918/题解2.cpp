#include <bits/stdc++.h>
using namespace std;

struct data{
    int pos,val;
};
bool cmp(data x,data y)
{
    return x.val < y.val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<data> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].val;
        a[i].pos = i+1;
    }
    sort(a.begin(),a.end(),cmp);
    
    int q;
    cin >> q;

    int m;
    
    for(int i=0;i<q;i++)
    {
        cin >> m;
        int left = 0,right = n,mid;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(a[mid].val > m) right = mid;
            if(a[mid].val < m) left = mid+1;
            if(a[mid].val == m)
            {
                cout << a[mid].pos << '\n';
                break;
            }
        }
        if(a[mid].val != m) cout << 0 << '\n';
    }
    return 0;
}

/*
解法2：利用结构体数组构建“位置/值”的对应关系，然后根据值进行
排序，然后就可以美美二分了
*/