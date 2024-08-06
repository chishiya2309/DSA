/*
Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N - 1 phép biến đổi nhân đôi dãy số. Phép nhân đôi dãy số dược định nghĩa như sau, giả sử dãy số bạn đang có là A thì việc gấp đôi dãy số sẽ thu được dãy A K A trong đó K là số nguyên nhỏ nhất chưa xuất hiện trong dãy số của A.

Ví dụ việc nhân đôi 1 dãy số từ số 1 với N = 4, tương ứng với 3 lần nhân đôi sẽ như sau : [1] => [1, 2, 1] => [1, 2, 1, 3, 1, 2, 1] => [1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1]

Cho số nguyên N và K, bạn hãy tìm số ở vị trí thứ K trong dãy số cuối cùng sau N - 1 lần nhân đôi dãy số ban đầu.

Đầu vào
Dòng duy nhất chứa 2 số nguyên dương N và K

Giới hạn
1<=N<=50

1<=K<=2^N - 1

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
3 2
Output 01
2
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int find(ll n, ll k)
{
    if(k == 1LL*pow(2, n - 1))
    {
        return n;
    }

    if(k < 1LL*pow(2, n - 1))
    {
        return find(n - 1, k);
    }else
    {
        return find(n - 1, k - 1LL*pow(2, n - 1));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    int res = find(n, k);
    cout << res;
    return 0;
}