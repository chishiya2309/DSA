/*
Cho mê cung A có n hàng, n cột. Một con chuột xuất phát từ ô (s, t) và di chuyển tới ô (u, v).

Nhiệm vụ của bạn là xác định số bước đi tối thiểu để con chuột con thể di chuyển từ ô (s, t) tới ô (u, v) hoặc xác định rằng không thể tìm được đường tới ô (u, v).

Mê cung A chỉ bao gồm các số 1 hoặc 0. Trong đó 1 đại diện cho đường đi và 0 đại diện cho vật cản, con chuột chỉ có thể di chuyển từ ô hiện tại sang các ô chung đỉnh với nó và có đường đi.

Đầu vào
Dòng đầu tiên là số nguyên dương n.

Dòng thứ 2 gồm 4 số nguyên s, t, u, v. Dữ liệu đảm bảo ô (s, t) có giá trị 1.

n dòng tiếp theo, mỗi dòng gồm n số nguyên mô tả mê cung A.

Giới hạn
2<=n<=1000

0<=A[i][j]<=1

Đầu ra
In ra số bước đi tối tiểu của con chuột hoặc in ra -1 nếu con chuột không thể đi đến nơi.

Ví dụ :
Input 01
Copy
10
9 6 9 3
1 1 0 1 1 1 1 0 0 1 
0 0 1 0 0 1 0 1 0 1 
1 1 1 1 0 0 0 1 1 0 
1 0 0 0 1 0 0 0 1 1 
1 0 1 0 0 1 0 1 1 0 
0 0 1 1 0 1 0 0 0 0 
1 1 0 1 0 1 1 0 0 0 
0 0 0 1 1 0 1 1 0 1 
1 0 1 0 0 1 0 0 1 1 
0 1 1 1 1 0 1 0 1 1
Output 01
Copy
3
*/

#include <bits/stdc++.h>

using namespace std;

int n, s, t, u, v;
int d[1003][1003];
int a[1003][1003];
int dem = 0;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1 , 1, 0, -1, -1};

int bfs(int i, int j)
{
    queue<pair<int, int>> q;
    d[i][j] = 0;
    a[i][j] = 0;
    q.push({i, j});
    while(!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        if(x == u && y == v)
        {
            return d[u][v];
        }
        for(int k = 0; k < 8; k++)
        {
            int inext = x + dx[k];
            int jnext = y + dy[k];
            if(inext >= 1 && inext <= n && jnext >= 1 && jnext <= n && a[inext][jnext] == 1)
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

    cout << bfs(s, t);

    return 0;
}