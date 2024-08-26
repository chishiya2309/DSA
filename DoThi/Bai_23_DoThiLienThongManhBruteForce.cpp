/*
Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy kiểm tra đồ thị có liên thông mạnh hay không? Bài này các bạn thử cài đặt bằng 3 cách là : brute force, thuật toán Tarjan, thuật toán Kosaraju.

Đầu vào
Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra 1 nếu đồ thị liên thông mạnh, ngược lại in ra 0.

Ví dụ :
Input 01
Copy
6 14
3 4
3 1
2 5
2 6
4 6
2 3
5 6
1 5
1 2
3 5
4 5
6 3
4 2
1 4
Output 01
Copy
1
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> ke[1003];
bool visited[1003];

void dfs(int u)
{
    visited[u] = 1;
    for(int j : ke[u])
    {
        if(!visited[j])
        {
            dfs(j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
    }

    for(int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        dfs(i);
        for(int j = 1; j <= n; j++)
        {
            if(!visited[j])
            {
                cout << 0;
                return 0;
            }
        }
    }
    
    cout << 1;

    return 0;
}