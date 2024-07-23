/*
Cho một bàn cờ vua có kích thước N x N. Hãy đếm số cách đặt N quân hậu vào bàn cờ sao cho không có 2 con hậu nào ăn nhau.

Đầu vào
Dòng duy nhất chứa số nguyên dương N

Giới hạn
2<=N<=12

Đầu ra
Kết quả của bài toán

Ví dụ :
Input 01
Copy
8
Output 01
Copy
92
*/

#include <bits/stdc++.h>

using namespace std;
int n;
int cot[100], xuoi[100], nguoc[100], x[100];
int cnt = 0;
void Try(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(cot[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j - 1] == 0)
        {
            x[i] = j;
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
            if(i == n)
            {
                cnt++;
            }else {
                Try(i + 1);
            }
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
        }

    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    Try(1);
    cout << cnt;
    return 0;
}