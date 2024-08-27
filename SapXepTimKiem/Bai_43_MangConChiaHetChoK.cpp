/*
Cho một mảng gồm n số nguyên, nhiệm vụ của bạn là đếm số mảng con ( dãy con các phần tử liên tiếp) mà tổng các giá trị chia hết cho n.

Đầu vào
Dòng nhập đầu tiên có số nguyên n: kích thước của mảng.

Dòng tiếp theo có n số nguyên a1, a2,…, an: nội dung của mảng.

Giới hạn
1≤n≤2⋅10^5; -10^9≤ai≤10^9

Đầu ra
In một số nguyên: số lượng mảng con thỏa mãn

Ví dụ :
Input 01
5
2 1 7 5 6
Output 01
3
Giải thích :
Dãy con thỏa mãn là (2, 1, 7), (5) và (2, 1, 7, 5)
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

    ll soMangCon = 0;
    map<int, int> mp;
    vector<int> dp(n + 1, 0);
    for(int i = 0; i < n; i++)
    {
        dp[i + 1] = (dp[i] + a[i] % n + n) % n;
    }
    mp[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        soMangCon += mp[dp[i]];
        mp[dp[i]]++;
    }

    cout << soMangCon;

    return 0;
}