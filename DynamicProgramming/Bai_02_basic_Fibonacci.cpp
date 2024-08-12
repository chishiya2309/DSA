/*
Cho dãy số Fibonacci với F[0] = 0, F[1] = 1, F[n] = F[n - 1] + F[n - 2] với n >= 2.

Hãy tính F[n] chia dư cho 10^9 + 7.

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
6
5
13
10
14
8
11
Output 01
Copy
5
233
55
377
21
89
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll F[1000003];
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i <= 1000000; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
        F[i] %= MOD;
    }

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << F[n] << endl;
    }

    return 0;
}