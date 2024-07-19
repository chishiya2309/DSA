#include<bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;

    int i = s.size() - 1;
    while(i >= 0 && s[i] == '1')
    {
        s[i] = '0';
        i--;
    }

    if(i >= 0)
    {
        s[i] = '1';
    }
    cout << s;
    return 0;
}
