/*
Cho số nguyên dương N, hãy đếm xem trong đoạn từ 0 tới N có bao nhiêu số nguyên tố.

Đầu vào
Dòng 1 là số bộ test T

T dòng tiếp theo mỗi dòng là 1 số nguyên không âm N

Giới hạn
1<=T<=10000

0<=N<=10^6

Đầu ra
Đưa ra kết quả của mỗi test trên 1 dòng

Ví dụ :
Input 01
Copy
5
39
68
26
87
6
Output 01
Copy
12
19
9
23
3
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
    
    dp[0] = dp[1] = 0;
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
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}