/*
Cho 2 số nguyên L, R, hãy đếm xem trong đoạn từ L tới R có bao nhiêu số nguyên tố.

Đầu vào
Dòng 1 là số bộ test T

T dòng tiếp theo mỗi dòng là 2 số nguyên không âm L, R

Giới hạn
1<=T<=10000

0<=L<=R<=10^6

Đầu ra
Đưa ra kết quả của mỗi test trên 1 dòng

Ví dụ :
Input 01
Copy
5
3 19
4 65
4 44
1 17
1 7
Output 01
Copy
7
16
12
7
4
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dp[1000003];
bool check(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return n > 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i <= 1000000; i++)
    {
        if(check(i))
        {
            dp[i] = dp[i - 1] + 1;
        }else {
            dp[i] = dp[i - 1];
        }
    }

    int t;
    cin >> t;
    while(t--)
    {
        int l, r;
        cin >> l >> r;
        if(l == 0)
        {
            cout << dp[r] << endl;
        }else {
            cout << dp[r] - dp[l - 1] << endl;
        }
    }

    return 0;
}