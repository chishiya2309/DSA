/*
Cho dãy số A[] = {a1, a2, ...an} và số tự nhiên K. Hãy tìm tất cả các dãy con của dãy số A[] sao cho tổng các phần tử của dãy con đó đúng bằng K. Các phần tử của dãy số A[] là nguyên dương và có giá trị khác nhau.

Ví dụ : với dãy con A[] = {5, 10, 15, 20, 25}, K = 50 ta có 3 dãy con {5, 10, 15, 20}, {5, 20, 25}, {10, 15, 25}.

Đầu vào
Dòng thứ 1 đưa vào số N là số lượng phần tử của dãy số A[] và số K;

Dòng tiếp theo đưa vào N phần tử của dãy số A[].

Giới hạn
1<=N<=15

1<=A[i],K<=100

Đầu ra
Đưa ra tất cả các dãy con của dãy số A[] thỏa mãn yêu cầu bài toán theo thứ tự từ điển, trong đó mỗi dãy con được bao bởi các ký tự [, ].

Nếu không có dãy con nào thỏa mãn yêu cầu bài toán, hãy đưa ra -1.

Ví dụ :
Input 01
Copy
10 26
12 11 9 10 6 8 14 7 5 13
Output 01
Copy
[5 6 7 8]
[5 7 14]
[5 8 13]
[5 9 12]
[5 10 11]
[6 7 13]
[6 8 12]
[6 9 11]
[7 8 11]
[7 9 10]
[12 14]
*/

#include <bits/stdc++.h>

using namespace std;
int n, k;
int a[16];
int X[16];
int sum = 0;
bool check = false;
void Try(int i, int index)
{
    for(int j = index; j <= n; j++)
    {
        X[i] = a[j];
        sum += a[j];
        if(sum == k)
        {
            check = true;
            cout << "[";
            for(int l = 1; l <= i; l++)
            {
                cout << X[l];
                if(l == i)
                {
                    cout << "]\n";
                }else {
                    cout << " ";
                }
            }
        }else if(sum < k)
        {
            Try(i + 1, j + 1);
        }
        sum -= a[j];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    Try(1, 1);
    if(!check)
    {
        cout << -1;
    }
    return 0;
}