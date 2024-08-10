/*
Cho số nguyên dương N, bạn hãy đếm số cách viết N dưới dạng tổng các số tự nhiên không vượt quá N, các hoán vị của nhau sẽ được coi là thỏa mãn.

Ví dụ N = 4 sẽ có 8 cách là 1+1+1+1, 1+2+1, 2+1+1, 1+1+2, 2+2, 1+3, 3+1, 4

Gợi ý : Viết N dấu * tương đương với N đơn vị của N, giữa N dấu * này sẽ có N - 1 khe giữa 2 dấu *. Lần lượt phân tích N dưới dạng tổng của 1, 2, 3, .. N số. Ví dụ N = 4 và phân tích dưới dạng tổng của 3 số thì ta cần chọn 2 vị trí để đặt vách ngăn giữa 3 khe trống, ví dụ * | * * | * ta có phân tích 1 + 2 + 1, * | * | * * ta có phân tích 1 + 1 + 2.

Đầu vào
Dòng duy nhất chứa số nguyên dương N

Giới hạn
1<=N<=10^16

Đầu ra
In ra đáp án của bài toán sau khi chia dư với 10^9 + 7

Ví dụ :
Input 01
Copy
4
Output 01
Copy
8
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

ll binpow(ll a, ll n)
{
    if(n == 1)
    {
        return a;
    }

    ll tmp = binpow(a, n / 2);
    if(n % 2 == 0)
    {
        return ((tmp % MOD) * (tmp % MOD)) % MOD;
    }else 
    {
        return ((tmp % MOD) * (tmp % MOD)) % MOD * a % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;

    ll res = binpow(2, n - 1);
    cout << res;
    return 0;
}