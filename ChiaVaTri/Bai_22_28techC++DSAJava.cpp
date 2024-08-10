/*
Cho xâu F được định nghĩa như sau :

F(1) = "28tech", F(2) = "C++", F(3) = "DSA JAVA"

F(N) = F(N - 3) + " " + F(N -2) + " " + F(N - 1).

Vì thế F(4) = "28tech C++ DSA JAVA", F(5) = "C++ DSA JAVA 28tech C++ DSA JAVA".

Nhiệm vụ của bạn là tìm từ thứ K trong xâu F(N), dữ liệu đảm bảo xâu F(N) có từ thứ K

Đầu vào
• Dòng 1 là T : số bộ test

• T dòng tiếp theo mỗi dòng gồm 2 số N, K

Giới hạn
• 1<=T<=100

• 1<=N<=60

• 1<=K<=10^16

Đầu ra
In ra kết quả của mỗi test trên từng dòng

Ví dụ :
Input 01
Copy
10
3 2
6 2
10 24
4 2
5 4
6 12
7 22
8 1
7 18
8 14
Output 01
Copy
JAVA
JAVA
JAVA
C++
28tech
DSA
C++
C++
C++
C++
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll F[100];

string find(ll n, ll k)
{
    if(n == 1)
    {
        return "28tech";
    }

    if(n == 2)
    {
        return "C++";
    }

    if(n == 3)
    {
        if(k == 1)
        {
            return "DSA";   
        }

        if(k == 2)
        {
            return "JAVA";
        }
    }

    if(k <= F[n - 3])
    {
        return find(n - 3, k);
    }

    if(k <= F[n - 3] + F[n - 2])
    {
        return find(n - 2, k - F[n - 3]);
    }

    return find(n - 1, k - F[n - 3] - F[n - 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    F[0] = 0;
    F[1] = F[2] = 1;
    F[3] = 2;
    for(int i = 4; i <= 60; i++)
    {
        F[i] = F[i - 3] + F[i - 2] + F[i - 1];
    }

    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << find(n, k) << endl;
    }

    return 0;
}