/*
Một số được gọi là số đặc biệt nếu nó chỉ chứa các chữ số 4 và 7, nhiệm vụ của bạn là hãy tìm số đặc biệt nhỏ nhất có tổng các chữ số bằng n.

Đầu vào
Dòng duy nhất chứa số nguyên dương n

Giới hạn
1<=n<=10^6

Đầu ra
In ra đáp án của bài toán, nếu không tồn tại đáp án thì in ra -1

Ví dụ :
Input 01
Copy
16
Output 01
Copy
4444
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int x = 0; 4 * x <= n; x++)
    {
        int tmp = n - 4 * x;
        if(tmp % 7 == 0)
        {
            int y = tmp / 7;
            while(x--)
            {
                cout << 4;
            }
            while(y--)
            {
                cout << 7;
            }
            return 0;
        }
    }
    cout << -1;
    return 0;
}