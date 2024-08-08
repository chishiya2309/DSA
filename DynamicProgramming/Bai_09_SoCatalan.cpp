/*
Số Catalan được định nghĩa đệ quy như sau : 

Một vài số đầu tiên trong dãy số Catalan : 1, 1, 2, 5, 14, 42, 142....

Bạn hãy tìm và in ra số Catalan thứ N sau khi chia dư cho 1e9 + 7

Đầu vào
Dòng 1 là là T : số bộ test

T dòng tiếp theo mỗi dòng là một số nguyên dương N

Giới hạn
1<=T<=1000

0<=N<=1000

Đầu ra
In ra kết quả mỗi test trên 1 dòng.

Ví dụ :
Input 01
Copy
3
0 1 3
Output 01
Copy
1 
1 
5
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int MOD = 1e9 + 7;
ll catalan[1003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    catalan[0] = catalan[1] = 1;

    for(int i = 2; i <= 1000; i++)
    {
        for(int j = 0; j < i; j++)
        {
            catalan[i] = (catalan[i] + catalan[j] * catalan[i - j - 1]) % MOD;
        }
    }

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        cout << catalan[n] << endl;
    }
    return 0;
}