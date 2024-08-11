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
    ll max2 = max(1LL*a[0]*a[1], 1LL*a[n - 1]*a[n - 2]);
    ll max3 = max(1LL*a[0]*a[1]*a[n - 1], 1LL*a[n - 1]*a[n - 2]*a[n - 3]);

    ll res = max(max2, max3);
    cout << res;
    
    return 0;
}