#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<int,int> aa,pair<int,int> bb)
{
    return aa.second<bb.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll n,s;
    cin >> n >> s;

    vector<pair<int,int>> data(n);
    ll total = 0;
    for(int i=0;i<n;i++)
    {
        cin >> data[i].first >>data[i].second;
        total += data[i].first;
    }
    sort(data.begin(),data.end(),cmp);

    /* 超时处理：
    ll sum = 0,ptr = 0;
    while(total > s)
    {
        sum += s;
        for(int i=ptr;i<n;i++)
        {
            data[i].second--;
            if(data[i].second == 0)
            {
                total -= data[i].first;
                ptr++;
            }
        }
    }

    for(int i=ptr;i<n;i++)
    {
        sum += data[i].first * data[i].second;
    }
    */

    //正确处理
    ll sum = 0,times = 0;
    for (register int i=0;i<n;i++)
    {
        if(total > s)
        {
            sum += (data[i].second - times) * s;
            total -= data[i].first;
            times += data[i].second - times;
        }
        else
        {
            sum += (data[i].second - times) * data[i].first;
        }
    }

    cout << sum;
    return 0;
}

/*
可以看到，本题本质上是一个贪心：如果当前所有仍需要继续训练的士兵一次训练所需的金币
总和小于 S，就使用组团训练；否则剩下的士兵全部单独训练。

但是由于数据量是10^5级别的，超时解法中的双层循环会超时

所以有正确处理：通过维护了一个times表示目前进行的集体训练的次数；
因为注意到在有序的数据中，直到data[i].second从1变成2对于处理产生
影响，所以就不去傻不拉唧地一个一个的遍历
*/