/*
Xâu Fibonacci được định nghĩa :

F(1) = "A"

F(2) = "B"

F(n) = F(n - 2) + F(n - 1) trong đó phép + tương đương phép nối chuỗi

Một số xâu đầu tiên trong xâu Fibonacci : "A", "B", "AB", "BAB", "ABBAB"....

Bạn hãy in ra ký tự thứ K trong xâu Fibonacci thứ N

Đầu vào
Dòng duy nhất chứa 2 số N và K

Giới hạn
1<=N<=92

1<=K<=10^18

Đầu ra
In ra đáp án tìm được

Ví dụ :
Input 01
5 3
Output 01
B
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll F[100];
char find(ll n, ll k)
{
    if(n == 1)
    {
        return 'A';
    }
    if(n == 2)
    {
        return 'B';
    }
    if(k <= F[n-2])
    {
        find(n - 2, k);
    }else 
    {
        find(n - 1, k - F[n - 2]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i <= 92; i++)
    {
        F[i] = F[i-1] + F[i - 2];
    }
    ll n, k;
    cin >> n >> k;
    char res = find(n, k);
    cout << res;
    return 0;
}