/*
Tìm số Fibonacci thứ N sau khi chia dư kết quả cho 10^9 + 7

Đầu vào
Dòng duy nhất chứa số nguyên dương N

Giới hạn
1<=N<=10^16

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
Copy
58
Output 01
Copy
286725742
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;
struct matran
{
    ll a[2][2];

    friend matran operator * (matran x, matran y)
    {
        matran tich;
        for(int i = 0;i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                tich.a[i][j] = 0;
                for(int k = 0; k < 2; k++)
                {
                    tich.a[i][j] += x.a[i][k] * y.a[k][j];
                    tich.a[i][j] %= MOD;
                }
            }
        }
        return tich;
    }
};

matran binpow(matran a, ll n)
{
    if(n == 1)
    {
        return a;
    }

    matran tmp = binpow(a, n / 2);
    if(n % 2 == 0)
    {
        return tmp * tmp;
    }else 
    {
        return tmp * tmp * a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    matran x;
    x.a[0][0] = 1;
    x.a[0][1] = 1;
    x.a[1][0] = 1;
    x.a[1][1] = 0;

    matran res = binpow(x, n);
    cout << res.a[0][1];
    return 0;
}