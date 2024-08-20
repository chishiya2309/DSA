/*
Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy đếm số lượng cạnh cầu của đồ thị.

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
10 1
5 2
10 5
10 6
5 3
10 4
Output 01
Copy
6
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
set<int> ke[1003];
bool visited[1003];
vector<pair<int, int>> dscanh;

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
        ke[x].insert(y);
        ke[y].insert(x);
        dscanh.push_back({x, y});
    }

    int tplt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            tplt++;
            dfs(i);
        }
    }

    int soCanhCau = 0;

    for(auto it : dscanh)
    {
        int dem = 0;
        memset(visited, 0, sizeof(visited));
        int x = it.first, y = it.second;
        ke[x].erase(y);
        ke[y].erase(x);
        for(int j = 1; j <= n; j++)
        {
            if(!visited[j])
            {
                dem++;
                dfs(j);
            }
        }
        if(dem > tplt)
        {
            soCanhCau++;
        }
        ke[x].insert(y);
        ke[y].insert(x);
    }

    cout << soCanhCau;

    return 0;
}