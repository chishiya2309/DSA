/*
Cho bàn cờ A cỡ NxN, một con mã ở ô (s, t) muốn di chuyển sang ô (u, v). Hãy tìm số bước tối thiểu để con mã có thể đến ô (u, v) hoặc xác định rằng con mã không thể đi tới nơi.

Bàn cờ A được mô tả bằng các giá trị 0, 1, trong đó ô có giá trị 1 thì con mã có thể tự do di chuyển đến ô này, ngược lại nếu giá trị tại một ô của bàn cơ là 0 thì con mã không thể di chuyển đến ô này.

Đầu vào
Dòng đầu tiên là số nguyên dương N.

Dòng thứ 2 gồm 4 số nguyên s, t, u, v. Dữ liệu đảm bảo ô (s, t) có giá trị 1.

N dòng tiếp theo, mỗi dòng gồm N số nguyên mô tả bàn cờ.

Giới hạn
2<=n<=1000

0<=A[i][j]<=1

Đầu ra
In ra số bước đi tối tiểu của con mã hoặc in ra -1 nếu con mã không thể đi đến nơi.

Ví dụ :
Input 01
Copy
10
6 7 8 9
0 1 1 0 1 0 1 0 1 0 
1 1 0 0 1 1 0 0 1 0 
1 1 0 1 1 0 0 1 0 0 
0 1 1 1 1 1 1 1 1 0 
0 0 1 0 0 1 1 1 1 1 
1 1 0 1 1 0 1 0 0 0 
1 0 0 0 0 1 1 0 1 1 
1 1 1 1 1 1 1 0 1 1 
1 0 0 1 1 1 0 1 1 1 
1 0 0 1 1 0 0 1 0 1
Output 01
Copy
4
*/

#include <bits/stdc++.h>

using namespace std;

int n, s, t, u, v;
int a[1003][1003];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int d[1003][1003];

int bfs()
{
    queue<pair<int, int>> q;
    q.push({s, t});
    a[s][t] = 0;
    while(!q.empty())
    {
        auto tmp = q.front();
        q.pop();
        int x = tmp.first;
        int y = tmp.second;
        if(x == u && y == v)
        {
            return d[u][v];
        }

        for(int k = 0; k < 8; k++)
        {
            int inext = x + dx[k];
            int jnext = y + dy[k];
            if(inext >= 0 && inext < n && jnext >= 0 && jnext < n && a[inext][jnext] == 1)
            {
                q.push({inext, jnext});
                a[inext][jnext] = 0;
                d[inext][jnext] = d[x][y] + 1;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    cin >> s >> t >> u >> v;
    for(int i = 1; i <= n; i++) 
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    int res = bfs();
    cout << res;

    return 0;
}