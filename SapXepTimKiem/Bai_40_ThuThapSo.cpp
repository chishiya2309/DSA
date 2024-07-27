/*
Bạn được cung cấp một mảng chứa mỗi số từ 1… n đúng một lần. Nhiệm vụ của bạn là thu thập các số từ 1 đến n theo thứ tự tăng dần. Trên mỗi vòng, bạn đi qua mảng từ trái sang phải và thu thập càng nhiều số càng tốt. Tổng số vòng sẽ là bao nhiêu?

Đầu vào
Dòng đầu tiên có số nguyên n: kích thước mảng.

Dòng tiếp theo có n số nguyên x1, x2,…, xn: các số trong mảng.

Giới hạn
1≤ n ≤2.10^5

Đầu ra
In một số nguyên: số vòng.

Ví dụ :
Input 01
5
4 2 1 5 3
Output 01
3
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n], pos[n + 1];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int last = 0, cnt = 1;
    for(int i = 1; i <= n; i++)
    {
        if(pos[i] < last)
        {
            cnt++;
        }
        last = pos[i];
    }
    cout << last;
    return 0;
}