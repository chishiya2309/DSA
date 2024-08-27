/*
Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy đếm số lượng đỉnh trụ của đồ thị.

Đầu vào
Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1=<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra số lượng đỉnh trụ của đồ thị

Ví dụ :
Input 01
Copy
10 6
5 4
5 2
10 2
10 7
5 3
10 1
Output 01
Copy
3
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
        ke[y].push_back(x);
    }

    int soThanhPhanLienThong = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            soThanhPhanLienThong++;
            dfs(i);
        }
    }

    int soDinhTru = 0;

    for(int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        int tmp = 0;
        for(int j = 1; j <= n; j++)
        {
            if(!visited[j])
            {
                tmp++;
                dfs(j);
            }
        }
        if(tmp > soThanhPhanLienThong)
        {
            soDinhTru++;
        }
    }

    cout << soDinhTru;

    return 0;
}