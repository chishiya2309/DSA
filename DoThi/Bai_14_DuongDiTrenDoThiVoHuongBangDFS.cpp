/*
Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy tìm đường đi theo thuật toán DFS từ đỉnh s tới đỉnh t.

Trong qúa trình mở rộng của thuật toán DFS, luôn ưu tiên mở rộng đỉnh có số thứ tự nhỏ hơn. Nếu không tồn tại đường đi thì in ra -1.

Đầu vào
Dòng đầu tiên là 4 số n, m, s, t, tương ứng với số lượng đỉnh, cạnh của đồ thị, đỉnh bắt đầu và đỉnh kết thúc.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=s,t<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra đường đi từ s tới t nếu có đường đi, trường hợp không tồn tại đường đi thì in ra -1.

Ví dụ :
Input 01
Copy
5 3 4 3
4 2
2 1
3 1
Output 01
Copy
4 2 1 3
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, s, t;
vector<int> ke[1003];
bool visited[1003];
int parent[1003];

void dfs(int u)
{
    visited[u] = 1;
    for(int j : ke[u])
    {
        if(!visited[j])
        {
            parent[j] = u;
            dfs(j);
        }   
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i++)
    {
        sort(ke[i].begin(), ke[i].end());
    }

    dfs(s);

    if(!visited[t])
    {
        cout << -1;
    }else
    {
        vector<int> v;
        while(t != s)
        {
            v.push_back(t);
            t = parent[t];
        }
        v.push_back(s);
        reverse(v.begin(), v.end());
        for(auto it : v)
        {
            cout << it << " ";
        }
    }

    return 0;
}