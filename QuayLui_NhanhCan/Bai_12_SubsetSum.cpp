/*
Cho mảng A[] gồm n phần tử, hãy xác định xem có thể chia mảng A[] thành 2 tập sao cho tổng của 2 tập bằng nhau hay không?

Đầu vào
Dòng đầu tiên là số nguyên n

Dòng thứ 2 gồm n số nguyên của mảng A[]

Giới hạn
1<=n<=20

1<=A[i]<=100

Đầu ra
In ra 1 nếu có thể chia mảng thành 2 phần bằng nhau, ngược lại in 0.

Ví dụ :
Input 01
Copy
5
9 9 4 4 5
Output 01
Copy
0
*/

#include <bits/stdc++.h>

using namespace std;
int n, a[21], x[21];
bool final = false;
void Try(int i)
{
    for(int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if(i == n)
        {
            int sum1 = 0, sum2 = 0;
            for(int i = 1; i <= n; i++)
            {
                if(x[i] == 0)
                {
                    sum1 += a[i];
                }else {
                    sum2 += a[i];
                }
            }
            if(sum1 == sum2)
            {
                final = true;
                return;
            }
        }else {
            Try(i + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    Try(1);
    if(final)
    {
        cout << 1;
    }else {
        cout << 0;
    }
    return 0;
}