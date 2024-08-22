/*
Cho mảng số nguyên A[] gồm N phần tử và số nguyên dương S, nhiệm vụ của bạn hãy xác định xem có thể tạo ra một tập con các phần tử trong mảng có tổng bằng S hay không?

Chú ý mỗi phần tử trong mảng chỉ được sử dụng một lần.

Đầu vào
Dòng đầu tiên gồm 2 số N và S

Dòng thứ 2 gồm N số của mảng A

Giới hạn
1<=N<=200

1<=S<=50000

1<=A[i]<=500

Đầu ra
In ra 1 nếu có tập con của A[] có tổng bằng S, ngược lại in ra 0

Ví dụ :
Input 01
Copy
5 10
2 2 1 6 3
Output 01
Copy
1
*/

#include <bits/stdc++.h>

using namespace std;

int n, s;
int a[203];
bool dp[203][100003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= s; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j >= a[i])
            {
                dp[i][j] = max(dp[i][j], dp[i- 1][j - a[i]]);
            }
        }
    }

    cout << dp[n][s];

    return 0;
}