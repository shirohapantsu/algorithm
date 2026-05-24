#include <bits/stdc++.h>
using namespace std;

int T,n;
int nums[14] = {-1,-1,1,7,4,2,6,8,10,18,22,20,28,68};
int nums2[7] = {88,108,188,200,208,288,688};

void yield_num(int n)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    if(n>=0 && n<14) cout << nums[n] << '\n';
    else if(n==17) cout << 200 << '\n';
    else
    {
        int q = n / 7;
        int r = n % 7;
        cout << nums2[r];
        for(int i=q-2;i>0;i--)
        {
            cout << 8;
        }
        cout << '\n';
    }
}

int main()
{
    cin >> T;
    for(int i=0;i<T;i++) 
    {
        cin >> n;
        yield_num(n);
    }
    return 0;
}

/*
爆搜挂着机 打表出省一

找规律desuwa
*/