/*
Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy xác định xem đồ thị có tồn tại chu trình hay không? Bài này các bạn cài đặt bằng 3 phương pháp : DFS, BFS và DSU.

Đầu vào
Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra 1 nếu đồ thị tồn tại chu trình, ngược lại in ra 0.

Ví dụ :
Input 01
10 11
10 5
10 4
10 1
10 3
5 2
5 4
10 8
5 3
5 1
10 6
10 9
Output 01
1
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> ke[1003];
bool visited[1003];
int parent[1003];
int chutrinh = 0;

void dfs(int u)
{
    visited[u] = true;
    for(int j : ke[u])
    {
        if(!visited[j])
        {
            parent[j] = u;
            dfs(j);
        }else 
        {
            if(j != parent[u])
            {
                chutrinh = 1;
            }
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
        ke[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            if(chutrinh == 1)
            {
                cout << 1;
                return 0;
            }
        }
    }

    cout << 0;

    return 0;
}