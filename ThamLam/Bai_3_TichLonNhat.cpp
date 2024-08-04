/*
Cho mảng A[] gồm N phần tử, nhiệm vụ của bạn là sắp xếp lại dãy số này để tổng A[0] * 0 + A[1] * 1 + A[2] * 2 + ... + A[N - 1] * (N - 1) đạt giá trị lớn nhất

Đầu vào
Dòng 1 là N

Dòng 2 là N số trong mảng A[] viết cách nhau 1 dấu cách

Giới hạn
1<=N<=10^6

1<=A[i]<=10^9

Đầu ra
In ra kết quả lớn nhất đạt được sau khi chia dư cho 10^9 + 7

Ví dụ :
Input 01
5 
1 1 2 1 3
Output 01
21
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x : a)
    {
        cin >> x;
    }
    sort(a.begin(), a.end());
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = ((sum % MOD) + (a[i] % MOD * (i % MOD)) % MOD) % MOD;
    }
    cout << sum;
    return 0;
}