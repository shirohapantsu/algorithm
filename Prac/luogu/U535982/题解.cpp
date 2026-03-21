#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;

    int n;
    string s;
    for(int i=0;i<t;i++)
    {
        cin >> n;
        cin >> s;
        int count1 = 0;
        int count2 = 0;
        for(int j=0;j<2*n;j+=2)
        {
            if(s[j] != 'A') count1++;
            if(s[j] != 'B') count2++;
        }
        cout << min(count1,count2) << '\n';
    }

    return 0;
}