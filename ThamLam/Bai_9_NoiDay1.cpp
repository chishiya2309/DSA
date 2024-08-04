/*
Cho N sợi dây, biết chi phí nối 2 sợ dây là tổng độ dài của 2 sợi dây đó. Nhiệm vụ của bạn là nối N sợi dây này thành 1 sao cho chi phí nối dây là nhỏ nhất

Đầu vào
Dòng 1 chứa số nguyên N

Dòng 2 chứa N số nguyên là độ dài các sợ dây

Giới hạn
1<=N<=10^5

Các sợi dây có độ dài không quá 10^5

Đầu ra
In ra chi phí nối dây tối thiểu

Ví dụ :
Input 01
4
1 2 3 4
Output 01
19
Giải thích :
(1, 2, 3, 4) => (3, 3, 4) => (6, 4) => (10), chi phí nối dây lần lượt là (1 + 2) + (3 + 3) + (6 + 4) = 19
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Q.push(x);
    }
    ll chiPhi = 0;
    while(Q.size() > 1)
    {
        ll tmp1 = Q.top();
        Q.pop();
        ll tmp2 = Q.top();
        Q.pop();
        chiPhi += tmp1 + tmp2;
        Q.push(tmp1 + tmp2);
    }
    cout << chiPhi;
    return 0;
}