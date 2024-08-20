/*
Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy thực hiện in ra danh sách các đỉnh được duyệt theo thuật toán BFS(s).

Trong quá trình mở rộng của thuật toán BFS luôn ưu tiên mở rộng đỉnh có số thứ tự nhỏ hơn trước.

Đầu vào
Dòng đầu tiên là 2 số n và m và s, tương ứng với số lượng đỉnh, cạnh của đồ thị và đỉnh bắt đầu duyệt.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=s<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra các đỉnh được duyệt theo thuật toán BFS(s).

Chú ý trong quá trình mở rộng các đỉnh của thuật toán BFS luôn lựa chọn duyệt các đỉnh có thứ tự nhỏ hơn trước.

Ví dụ :
Input 01
Copy
5 7 5
4 1
5 3
4 3
5 1
3 2
4 2
2 1
Output 01
Copy
5 1 3 2 4
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, s;
vector<int> ke[1003];
bool visited[1003];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for(int j : ke[x])
        {
            if(!visited[j])
            {
                q.push(j);
                visited[j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> s;
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

    bfs(s);

    return 0;
}