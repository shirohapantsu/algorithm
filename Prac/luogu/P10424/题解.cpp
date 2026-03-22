#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    for(int i=1;i<=n;i+=2)
    {
        int tmp = i;
        int flag = 1;
        int res = 0;
        while(tmp > 0)
        {
            if(tmp % 2 != flag)
            {
                res = -1;
                break;
            }
            flag = !flag;
            tmp/=10;
        }
        if(res == 0) count++;
    }
    cout << count;
    return 0;
}

/*
简单的枚举和模拟
*/