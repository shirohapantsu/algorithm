#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    map<int,int> a;
    int tmp;
    for(int i=0;i<n;i++)
    {
        cin >> tmp;
        a[tmp] = i+1;
    }
    
    int q;
    cin >> q;
    int m;
    for(int i=0;i<q;i++)
    {
        cin >> m;
        cout << a[m] << '\n';
    }
    return 0;
}

/*
解法1：利用map储存键值对的特性存储num:pos键值对，直接通过索引完成查找

这道题考察的实际上就是大量的查找的算法优化，对于100000的q，常规遍历肯定会超时

这里其实是偷了懒==，轮椅做法没啥好说的，直接快进解法2
*/