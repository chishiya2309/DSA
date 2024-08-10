/*
Trong lớp học của Tèo có các thanh domino hình chữ nhật có chiều rộng a và có chiều cao b. Tèo hiện là học sinh lớp 1, thầy giáo có giao cho Tèo một bài toán đó là hãy tìm 1 bảng hình vuông có cạnh nhỏ nhất sao cho có thể xếp n thanh domino vào hình vuông này. Tèo không nhất thiết phải xếp kín cái bảng hình vuông này nhưng không được phép xoay ngang thanh domino. Dưới đây là một ví dụ về cách xếp thanh domino có a = 2, b = 3 vào bảng hình vuông có cạnh 9

Đầu vào
3 số a, b, n trên 1 dòng

Giới hạn
1<=n,a,b<=10^9

Đầu ra
In ra chiều dài cạnh của hình vuông nhỏ nhất tìm được.

Ví dụ :
Input 01
Copy
2 3 10
Output 01
Copy
9
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll a, ll b, ll n, ll c)
{
    return (c / a) >= (double)n / (c / b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b, n;
    cin >> a >> b >> n;


    ll left = 0, right = 1e18;
    ll res = -1;

    while(left <= right)
    {
        ll mid = (left + right) / 2;
        if(check(a, b, n, mid))
        {
            res = mid;
            right = mid - 1;
        }else 
        {
            left = mid + 1;
        }
    }

    cout << res;
    return 0;
}