/*
Cho một bảng số kích thước N x M. Chi phí khi đi qua ô (i,j) bằng A[i][j].

Nhiệm vụ của bạn là hãy tìm một đường đi từ ô (1, 1) tới ô (N, M) sao cho chi phí là nhỏ nhất.

Tại mỗi ô, bạn được phép đi sang trái, sang phải, đi lên trên và xuống dưới.

Đầu vào
• Dòng 1 bắt đầu bởi hai số nguyên N và M.

• N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j]

Giới hạn
• 1 ≤ N, M ≤ 500

• 0 ≤ A[i][j] ≤ 9

Đầu ra
In ra một số nguyên là chi phí nhỏ nhất cho đường đi tìm được.

Ví dụ :
Input 01
Copy
6 7
0 3 6 0 5 9 1 
6 5 4 4 0 7 6 
4 0 2 1 5 6 1 
2 7 7 3 3 1 6 
4 4 9 6 9 7 2 
3 6 4 4 1 9 2
Output 01
Copy
28
*/

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m;
int a[503][503];
int d[503][503];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void nhap()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            d[i][j] = 1e9;
        }
    }
}

void Dijkstra()
{
    priority_queue<iii, vector<iii>, greater<iii>> q;
    d[1][1] = a[1][1];
    q.push({a[1][1], {1, 1}});

    while(!q.empty())
    {
        iii p = q.top();
        q.pop();

        int w = p.first;
        int x = p.second.first;
        int y = p.second.second;

        if(w > d[x][y])
        {
            continue;
        }

        for(int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m)
            {
                if(d[nx][ny] > w + a[nx][ny])
                {
                    d[nx][ny] = w + a[nx][ny];
                    q.push({d[nx][ny], {nx, ny}});
                }   
            }
        }
    }

    cout << d[n][m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    nhap();

    Dijkstra();

    return 0;
}