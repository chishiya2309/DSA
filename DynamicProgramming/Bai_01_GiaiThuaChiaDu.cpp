/*
Đề bài rất đơn giản, bạn hãy tính N! chia dư cho (10^9 + 7).

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
11
6
8
10
13
Output 01
Copy
39916800
720
40320
3628800
227020758
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
    
    F[0] = 1;
    for(int i = 1; i <= 1000000; i++)
    {
        F[i] = i * F[i - 1];
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