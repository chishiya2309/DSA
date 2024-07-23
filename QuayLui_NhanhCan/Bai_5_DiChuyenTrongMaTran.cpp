/*
Cho ma trận A[] gồm N hàng và M cột. Nhiệm vụ của bạn là đếm tất cả các đường đi từ phần tử A[1][1] đến phần tử A[N][M]. Bạn chỉ được phép dịch chuyển xuống dưới hoặc sang phải phần tử liền kề với vị trí hiện tại.

Đầu vào
Dòng 1 là hai số N và M

Dòng tiếp theo đưa vào các phần tử của ma trận A[][]

Giới hạn
1≤M, N,<=10

A[i][j]≤10000

Đầu ra
Đưa ra số cách di chuyển

Ví dụ :
Input 01
Copy
3 5
4 6 8 3 1 
9 8 8 9 1 
10 6 3 4 5
Output 01
Copy
15
*/

#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[11][11];
int cnt = 0;
int dx[] = {1, 0};
int dy[] = {0, 1};
void Try(int i, int j)
{
    if(i == n && j == m)
    {
        cnt++;
    }
    for(int k = 0; k < 2; k++)
    {
        int inext = i + dx[k];
        int jnext = j + dy[k];
        if(inext >= 1 && inext <= n && jnext >= 1 && jnext <= m)
        {
            Try(inext, jnext);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    Try(1, 1);
    cout << cnt;
    return 0;
}