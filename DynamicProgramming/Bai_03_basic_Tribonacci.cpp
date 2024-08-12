/*
Cho dãy số Tribonacci với F[0] = 0, F[1] = 0, F[2] = 1, F[n] = F[n - 1] + F[n - 2] + F[n - 3] với n >= 3.

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
7
8
14
12
7
9
7
12
Output 01
Copy
24
927
274
13
44
13
274
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
    
    F[0] = F[1] = 0;
    F[2] = 1;
    for(int i = 3; i <= 1000000; i++)
    {
        F[i] = F[i - 1] + F[i - 2] + F[i - 3];
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