/*
Cho ma trận A[][] là ma trận vuông cỡ N x N. Hãy tính kết quả A^K và chia dư các phần tử trong ma trận kết quả cho 10^9 + 7

Đầu vào
Dòng đầu tiên chứa 2 số nguyên dương N và K

N dòng tiếp theo là các phần tử trong ma trận A

Giới hạn
1<=N<=10

1<=K<=10^9

0<=A[i][j]<=1000

Đầu ra
In ra ma trận đáp án

Ví dụ :
Input 01
Copy
2 3
712 141 
55 619
Output 01
Copy
376787593 188740908 
73622340 252298909
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int n;
const int MOD = 1e9 + 7;

struct matran
{
    ll a[11][11];

    friend matran operator * (matran x, matran y)
    {
        matran tich;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                tich.a[i][j] = 0;
                for(int k = 0; k < n; k++)
                {
                    tich.a[i][j] += x.a[i][k] * y.a[k][j];
                    tich.a[i][j] %= MOD;
                }
            }
        }
        return tich;
    }
};

matran binpow(matran x, int k)
{
    if(k == 1)
    {
        return x;
    }

    matran tmp = binpow(x, k / 2);
    if(k % 2 == 0)
    {
        return tmp * tmp;
    }else 
    {
        return tmp * tmp * x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int k;
    cin >> k;

    matran x;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> x.a[i][j];
        }
    }

    matran res = binpow(x, k);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << res.a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}