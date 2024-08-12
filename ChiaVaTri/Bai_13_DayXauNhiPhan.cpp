/*
Xâu nhị phân F được định nghĩa như sau :

F(1) = "0"

F(2) = "1"

F(n) = F(n - 2) + F(n - 1) trong đó phép + tương đương phép nối chuỗi.

Bạn hãy tìm kí tự thứ K trong xâu F(N)

Đầu vào
1 Dòng duy nhất chứa 2 số nguyên N và K

Giới hạn
2<=N<=92

1<=K<=10^18

Đầu ra
In ra kí tự là đáp án của bài toán

Ví dụ :
Input 01
Copy
7 7
Output 01
Copy
0
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll F[100];
char find(ll n, ll k)
{
    if(n == 1)
    {
        return '0';
    }

    if(n == 2)
    {
        return '1';
    }

    if(k <= F[n - 2])
    {
        return find(n - 2, k);
    }
    return find(n - 1, k - F[n - 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    F[0] = 0;
    F[1] = F[2] = 1;
    for(int i = 3; i <= 92; i++)
    {
        F[i] = F[i - 2] + F[i - 1];
    }

    ll n, k;
    cin >> n >> k;
    cout << find(n, k);

    return 0;
}