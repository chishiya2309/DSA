/*
Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy thực hiện in ra danh sách các đỉnh được duyệt theo thuật toán DFS(s).

Chú ý trong quá trình mở rộng các đỉnh của thuật toán DFS luôn lựa chọn duyệt các đỉnh có thứ tự nhỏ hơn trước.

Đầu vào
Dòng đầu tiên là 2 số n và m và s, tương ứng với số lượng đỉnh, cạnh của đồ thị và đỉnh bắt đầu duyệt.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=s<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra các đỉnh được duyệt theo thuật toán DFS(s).
Ví dụ :
Input 01
Copy
5 10 4
5 1
4 5
4 2
4 3
1 5
3 5
5 3
3 1
1 4
5 2
Output 01
Copy
4 2 3 1 5
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, s;
int a[1003][1003];
vector<int> ke[1003];
bool visited[1003];

void dfs(int u)
{
    cout << u << " ";
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
    
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
    }

    for(int i = 1; i <= n; i++)
    {
        sort(ke[i].begin(), ke[i].end());
    }

    dfs(s);

    return 0;
}