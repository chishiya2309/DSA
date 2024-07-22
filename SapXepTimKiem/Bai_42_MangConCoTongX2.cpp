/*
Cho một mảng gồm n số nguyên, nhiệm vụ của bạn là đếm số mảng con (dãy con các phần tử liên tiếp) có tổng bằng x.

Đầu vào
Dòng đầu tiên có hai số nguyên n và x: kích thước của mảng và tổng mục tiêu x.

Dòng tiếp theo có n số nguyên a1, a2,…, an: các phần tử trong mảng

Giới hạn
1≤n≤2⋅10^5

-10^9≤x, ai≤10^9

Đầu ra
In một số nguyên: số lượng mảng con cần thiết.

Ví dụ :
Input 01
5 7
2 4 1 2 7
Output 01
3
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int &x : a)
    {
        cin >> x;
    }
    map<ll, int> sum_count;
    sum_count[0] = 1;
    ll sum = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i];
        cnt += sum_count[sum - x];
        sum_count[sum]++;
    }
    cout << cnt;
    return 0;
}