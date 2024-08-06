/*
Cho dãy số A gồm N phần tử là các số nguyên. Hãy tính tích lớn nhất của 2 hoặc 3 phần tử trong dãy.

Đầu vào
Dòng đầu tiên là N

Dòng thứ 2 là N phần tử của mảng A

Giới hạn
1<=N<=1000

0<=abs(A[i])<=10^6

Đầu ra
In ra tích lớn nhất của 2 hoặc 3 phần tử trong mảng

Ví dụ :
Input 01
Copy
5
1 2 4 2 28
Output 01
Copy
224
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
    {
        cin >> x;
    }
    sort(a.begin(), a.end());
    ll tich2 = max((ll)a[0]*a[1], (ll)a[n-1]*a[n-2]);
    ll tich3 = max((ll)a[0]*a[1]*a[n-1], (ll)a[n-1]*a[n-2]*a[n-3]);
    ll res = max(tich2, tich3);
    cout << res;
    return 0;
}