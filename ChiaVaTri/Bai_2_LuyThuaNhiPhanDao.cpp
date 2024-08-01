/*
Cho số nguyên dương N và M, trong đó M là số ngược của N, ví dụ N = 1234 thì M = 4321.

Bạn hãy tính N^M và chia dư kết quả cho 10^9 + 7

Đầu vào
Dòng duy nhất chứa số nguyên dương N

Giới hạn
1<=N<=10^16

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
999995841
Output 01
987348397
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
    ll n, m;
    cin >> n;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    m = stoll(s);
    ll res = powMod(n, m);
    cout << res;
    return 0;
}