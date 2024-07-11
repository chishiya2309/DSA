/*
Trong lớp học của Tèo có các thanh domino hình chữ nhật có chiều rộng a và có chiều cao b. Tèo hiện là học sinh lớp 1, thầy giáo có giao cho Tèo một bài toán đó là hãy tìm 1 bảng hình vuông có cạnh nhỏ nhất sao cho có thể xếp n thanh domino vào hình vuông này. Tèo không nhất thiết phải xếp kín cái bảng hình vuông này nhưng không được phép xoay ngang thanh domino.
*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(ll a, ll b, ll n, ll C)
{
    return (C / a) >= (double)n / (C / b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, n;
    cin >> a >> b >> n;
    ll l = 0, r = max(a, b) * n;
    ll res = -1;
    while(l <= r)
    {
        ll mid = (l + r) / 2;
        if(check(a, b, n, mid))
        {
            res = mid;
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    cout << res;
    return 0;
}
