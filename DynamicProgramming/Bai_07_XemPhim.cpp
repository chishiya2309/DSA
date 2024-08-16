/*
John có một đàn bò. Một ngày đẹp trời, anh ta quyết định mua xe tải với khả năng chở được C kg (1000 ≤ C ≤ 25000) để đưa những con bò đi xem phim. Cho số con bò là N (20 ≤ N ≤ 100) và khối lượng w[i] của từng con (đều nhỏ hơn C), hãy cho biết khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.

Đầu vào
Dòng 1 là 2 số nguyên C và N cách nhau bởi dấu cách

Dòng 2 lần lượt các số nguyên : w[i]

Giới hạn
1000 ≤ C ≤ 25000

20 ≤ N ≤ 100

w[i] <= C

Đầu ra
Một số nguyên là tổng khối lượng bò lớn nhất mà John có thể mang đi xem phim.

Ví dụ :
Input 01
Copy
259 5
81 58 42 33 61
Output 01
Copy
242
*/

#include <bits/stdc++.h>

using namespace std;

int c, n, w[103];
int dp[103][25003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> c >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + w[i]);
            }
        }
    }

    cout << dp[n][c];

    return 0;
}