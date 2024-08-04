/*
Cho mảng A[], B[] đều có N phần tử. Nhiệm vụ của bạn là tìm giá trị lớn nhất của tích A[0] x B[0] + A[1] x B[1] + .. + A[N-1] x B[N-1], bạn được phép thay đổi thứ tự các phần tử trong mảng A[] và B[] trước khi tính toán.

Đầu vào
Dòng 1 chứa số nguyên dương N

Dòng 2 chứa N số nguyên của mảng A[]

Dòng 3 chứa N số nguyên của mảng B[]

Giới hạn
1<=N<=10^6

0<=A[i], B[i]<=10^6

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
3
1 2 1 
2 6 6
Output 01
20
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll &x : a)
    {
        cin >> x;
    }
    for(ll &x : b)
    {
        cin >> x;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i] * b[i];
    }
    cout << sum;
    return 0;
}