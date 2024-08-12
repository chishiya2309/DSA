/*
Cho ma trận đường đi gồm N hàng và M cột, mỗi ô trên ma trận là ký tự * tương ứng với đường đi và x tương ứng với vật cản. Bạn hãy đếm số lượng đường đi từ ô (1, 1) tới ô (N, M) biết rằng bạn chỉ có thể đi từ ô hiện tại sang phải hoặc xuống dưới nếu chúng không có vật cản.

Đầu vào
Dòng 1 là là N và M

N dòng tiếp theo là các dòng của ma trận

Giới hạn
1<=N,M<=1000

Đầu ra
In ra kết quả của bài toán sau khi chia dư cho 1e9 + 7.

Ví dụ :
Input 01
5 5
* * * * * 
x * * * x 
x * x * * 
x * * * * 
* x * x *
Output 01
7
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1003][1003];
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    char a[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    if(a[0][0] == '*')
    {
        dp[0][0] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == 'x')
            {
                continue;
            }
            
            if(i > 0)
            {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }

            if(j > 0)
            {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[n - 1][m - 1];

    return 0;
}