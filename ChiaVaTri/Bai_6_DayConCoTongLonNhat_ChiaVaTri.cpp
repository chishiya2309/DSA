/*
Cho dãy số nguyên A[] gồm N phần tử, bạn hãy là tính tổng của dãy con liên tiếp có tổng lớn nhất.

Đầu vào
Dòng đầu tiên chứa số nguyên dương N

Dòng thứ 2 chứa N số nguyên của dãy A[]

Giới hạn
1<=N<=10^5

1<=abs(A[i])<=10^6

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
Copy
5
-3 6 1 -3 6
Output 01
Copy
10
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, a[100003];

ll crossing_sum(int a[], int l, int m, int r)
{
    ll sum_left = 0, max_sum_left = 0;
    for(int i = m; i >= l; i--)
    {
        sum_left += a[i];
        max_sum_left = max(max_sum_left, sum_left);
    }

    ll sum_right = 0, max_sum_right = 0;
    for(int i = m + 1; i <= r; i++)
    {
        sum_right += a[i];
        max_sum_right = max(max_sum_right, sum_right);
    }

    return max_sum_left + max_sum_right;
}

ll find(int a[], int l, int r)
{
    if(l == r)
    {
        return a[l];
    }

    int m = (l + r) / 2;
    return max({
        find(a, l, m),
        find(a, m + 1, r),
        crossing_sum(a, l, m, r)
    });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << find(a, 0, n - 1);

    return 0;
}