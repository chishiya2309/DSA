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

ll crossing_sum(int a[], int l, int mid, int r)
{
    ll sum_right = 0, max_sum_right = 0;
    for(int i = mid + 1; i <= r; i++)
    {  
        sum_right += a[i];
        max_sum_right = max(max_sum_right, sum_right);
    }

    ll sum_left = 0, max_sum_left = 0;
    for(int i = mid; i >= l; i--)
    {
        sum_left += a[i];
        max_sum_left = max(max_sum_left, sum_left);
    }

    return max_sum_left + max_sum_right;
}

ll find(int a[], int l, int r)
{
    if(l == r)
    {
        return a[l];
    }

    int mid = (l + r) / 2;
    return max({
        find(a, l, mid),
        find(a, mid + 1, r),
        crossing_sum(a, l, mid, r)
    });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int a[n];
    for(int &x : a)
    {
        cin >> x;
    }

    ll res = find(a, 0, n - 1);
    cout << res;
    return 0;
}