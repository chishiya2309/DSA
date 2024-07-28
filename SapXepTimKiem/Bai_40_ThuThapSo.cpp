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
Giải thích :
Vòng 1 chọn số 1, vòng 2 chọn số 2 và 3, vòng 3 chọn số 4 và 5 Ở mỗi vòng bạn được chọn số x nếu như tất cả các số từ 1 tới x-1 đã được chọn trước đó rồi, mỗi vòng bạn có thể chọn nhiều số cùng 1 lúc.
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
    int dem = 1, last = 0;
    for(int i = 1; i <= n; i++)
    {
        if(pos[i] < last)
        {
            dem++;
        }
        last = pos[i];
    }
    cout << dem;
    return 0;
}