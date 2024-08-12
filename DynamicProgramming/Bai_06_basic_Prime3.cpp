/*
Cho số nguyên dương N, hãy tính tích các số nguyên tố trong đoạn từ 0 đến N. Khi N = 0 hoặc 1 thì đáp án là 0.

Đầu vào
Dòng 1 là số bộ test T

T dòng tiếp theo mỗi dòng là 1 số nguyên không âm N

Giới hạn
1<=T<=10000

0<=N<=10^6

Đầu ra
Đưa ra kết quả của mỗi test trên 1 dòng, vì kết quả quá lớn nên hãy chia dư cho 10^9 + 7.

Ví dụ :
Input 01
Copy
5
20
16
10
22
29
Output 01
Copy
9699690
30030
210
9699690
469693188
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll dp[1000003];
const int MOD = 1e9 + 7;

bool prime[1000003];
void sang()
{
    for(int i = 0; i <= 1000000; i++)
    {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for(int i = 2; i <= sqrt(1000000); i++)
    {
        if(prime[i])
        {
            for(int j = i * i; j <= 1000000; j += i)
            {
                prime[j] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    sang();
    dp[0] = dp[1] = 0;
    dp[2] = 2;
    for(int i = 3; i <= 1000000; i++)
    {
        if(prime[i])
        {
            dp[i] = dp[i - 1] * i;
            dp[i] %= MOD;
        }else {
            dp[i] = dp[i - 1];
        }
    }

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}