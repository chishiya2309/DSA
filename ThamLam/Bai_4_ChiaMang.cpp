/*
Cho mảng A[] gồm N phần tử và số nguyên K, bạn hãy chia mảng thành 2 tập con (không cần liên tiếp) có K và N - K phần tử sao cho độ chênh lệch giữa tổng của 2 tập con là lớn nhất có thể.

Đầu vào
Dòng 1 chứa 2 số nguyên N và K

Dòng thứ 2 gồm N số của mảng A[]

Giới hạn
1<=K<=N<=10^6

0<=A[i]<=10^9

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
Copy
5 3
2 8 9 1 3
Output 01
17
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x : a)
    {
        cin >> x;
    }
    sort(a.begin(), a.end());
    ll sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for(int i = 0; i < n; i++)
    {
        if(i < k)
        {
            sum1 += a[i];
        }else {
            sum2 += a[i];
        }
    }

    sort(a.begin(), a.end(), greater<int>());
    for(int i = 0; i < n; i++)
    {
        if(i < k)
        {
            sum3 += a[i];
        }else {
            sum4 += a[i];
        }
    }
    cout << max(abs(sum1 - sum2), abs(sum3 - sum4));
    return 0;
}