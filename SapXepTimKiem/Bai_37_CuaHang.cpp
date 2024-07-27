/*
Bạn được cho biết thời gian đến và đi của n khách hàng trong một nhà hàng. Số lượng khách hàng có mặt tại cửa hàng ở 1 thời điểm nhiều nhất là bao nhiêu?

Đầu vào
Dòng nhập đầu tiên có số nguyên n: số lượng khách hàng. Sau đó, có n dòng mô tả khách hàng.

Mỗi dòng có hai số nguyên a và b: thời gian đến và đi của một khách hàng. Bạn có thể cho rằng tất cả thời gian đến và đi là khác nhau.

Giới hạn
1≤ n, m ≤2.10^5

1≤ a, b ≤10^9

Đầu ra
In một số nguyên: số lượng khách hàng tối đa.

Ví dụ :
Input 01
3
5 8
2 4
3 9
Output 01
2
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> Time;
    for(int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        Time.push_back({start, 1});
        Time.push_back({end, -1});
    }
    int cnt = 0, maxCus = INT_MIN;
    sort(Time.begin(), Time.end());
    for(auto x : Time)
    {
        cnt += x.second;
        maxCus = max(maxCus, cnt);
    }
    cout << maxCus;
    return 0;
}