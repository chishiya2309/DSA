/*
Dãy số nguyên dương vô hạn A[] được định nghĩa một cách đệ quy như sau:

A[0] = 0; A[1] = 1; A[i] = A[i-1] + A[i-2] với mọi n ≥ 2.

Cho số nguyên dương N không quá 10^9. Hãy xác định số thứ N trong dãy A[].

Đầu vào
Dòng duy nhất chứa số nguyên dương N

Giới hạn
1<=N<=10^9

Đầu ra
In ra đáp án của bài toán sau khi chia dư cho 10^9 + 7

Ví dụ :
Input 01
Copy
999992343
Output 01
Copy
865905443
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
        for(int i = 0; i < 2; i++)
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

matran binpow(matran x, int n)
{
    if(n == 1)
    {
        return x;
    }

    matran tmp = binpow(x, n / 2);
    if(n % 2 == 0)
    {
        return tmp * tmp;
    }else {
        return tmp * tmp * x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    matran x;
    x.a[0][0] = 1;
    x.a[0][1] = 1;
    x.a[1][0] = 1;
    x.a[1][1] = 0;

    int n;
    cin >> n;

    matran res = binpow(x, n);
    cout << res.a[0][1];

    return 0;
}