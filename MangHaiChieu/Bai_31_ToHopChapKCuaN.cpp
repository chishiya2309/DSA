/*
Bạn hãy tính tổ hợp chập K của N và chia dư cho 10^9 + 7

Đầu vào
• Dòng 1 là số test case T

• T dòng tiếp theo mỗi dòng gồm 2 số N và K

Giới hạn
• 1<=T<=10000

• 0<=K<=N<=1000

Đầu ra
In ra kết quả của mỗi test trên 1 dòng

Ví dụ :
Input 01
5
9 0
13 8
16 7
9 9
7 6
Output 01
1
1287
11440
1
7
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll nCk[1003][1003];
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int n = 0; n <= 1000; n++)
    {
        for(int k = 0; k <= n; k++)
        {
            if(k == 0 || k == n)
            {
                nCk[n][k] = 1;
            }else 
            {
                nCk[n][k] = nCk[n - 1][k - 1] + nCk[n - 1][k];
                nCk[n][k] %= MOD;
            } 
        }
    }

    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        cout << nCk[n][k] << endl;
    }

    return 0;
}