/*
Cho ma trận vuông A[][] kích thước N x N. Nhiệm vụ của bạn là hãy tính ma trận A^K với K là số nguyên cho trước.

Sau đó, tính tổng các phần tử của cột cuối cùng. Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 10^9+7.

Đầu vào
Dòng đầu tiên chứa 2 số nguyên dương N và K

N dòng tiếp theo là các phần tử trong ma trận A

Giới hạn
1<=N<=10

1<=K<=10^9

0<=A[i][j]<=1000

Đầu ra
In ra đáp án của bài toán theo yêu cầu

Ví dụ :
Input 01
Copy
2 2
216 71 
923 906
Output 01
Copy
966031
*/

#include <bits/stdc++.h>
#define ll long long
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
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += res.a[i][n - 1];
        ans %= MOD;
    }

    cout << ans;
    
    return 0;
}