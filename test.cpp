/*
Nếu n = 0 thì return 2
n = 1 thì return 3
nếu n >= 2 thì tính bằng f[n - 1] - f[n - 2]
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int find(ll n)
{
    if(n == 0)
    {
        return 2;
    }

    if(n == 1)
    {
        return 3;
    }

    return find((n - 1) - (n - 2) - (n - 2));
}

signed main()
{
    ll n;
    cin >> n;
    cout << find(n);
}