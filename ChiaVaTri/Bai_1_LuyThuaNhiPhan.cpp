/*
Cho 2 số nguyên N và K bạn hãy tính N^K, kết quả được chia dư với 10^9 + 7

Đầu vào
Dòng duy nhất chứa 2 số N và K

Giới hạn
1<=N<=10^6

1<=K<=10^9

Đầu ra
Kết quả của bài toán

Ví dụ :
Input 01
994402 999992619
Output 01
925329307
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
ll powMod(ll n, ll k)
{
    if(k == 0)
    {
        return 1;
    }
    ll tmp = powMod(n, k / 2);
    if(k % 2 == 0)
    {
        return (tmp % MOD) * tmp % MOD;
    }else {
        return ((tmp % MOD) * (tmp % MOD)) % MOD * n % MOD;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll res = powMod(n, k);
    cout << res;
    return 0;
}